#include<iostream>
#include<cstdio>
using namespace std;
const int sudokusize=3;
const int edgelength=sudokusize*sudokusize;
struct point
{
    int up, down, right, left, column, sum;
    int x,y,num;
};
point lists[4*edgelength * edgelength * edgelength + edgelength * sudokusize+1000];
int ans[4 * edgelength * edgelength+1000];
int map[edgelength+2][edgelength+2];
int solvedmap[edgelength+2][edgelength+2];
int nine(int x,int y)
{

    return ((x - 1) / sudokusize) * sudokusize + (y - 1) / sudokusize + 1;

}
void insert(int sign ,int x,int y,int num)
{
    int col[4]= {(x-1)*edgelength+y,
                 edgelength*edgelength+(x-1)*edgelength+num,
                 2*edgelength*edgelength+(y-1)*edgelength+num,
                 3*edgelength*edgelength+(nine(x,y)-1)*edgelength+num
                };
    lists[sign].up = col[0];
    lists[sign].down = col[1];
    lists[sign].left = col[2];
    lists[sign].right = col[3];
    for (int i = 0; i <= 3; i++)
    {
        lists[sign + i].left = sign + i - 1;
        lists[sign + i].right = sign + i + 1;
        lists[lists[col[i]].up].down = sign + i;
        lists[sign + i].up = lists[col[i]].up;
        lists[col[i]].up = sign + i;
        lists[sign + i].down = col[i];
        lists[sign + i].column = col[i];
        lists[col[i]].sum++;
        lists[sign + i].num = num;
        lists[sign + i].x = x;
        lists[sign + i].y = y;
    }
    lists[sign].left = sign + 3;
    lists[sign + 3].right = sign;
}
void makeup()
{
    int len = 4 *edgelength* edgelength;
    for(int i=1; i<=len; i++)
    {
        lists[i].left=i-1;
        lists[i].right= i + 1;
        lists[i].up = i;
        lists[i].down= i;
        lists[i].column = i;
    }
    lists[0].left=len;
    lists[0].right = 1;
    lists[len].right = 0;
    lists[len].sum = len;
    int sign = len+1;
    //int lastcolumn = 1;
    for(int i=1; i<=edgelength; i++)for(int j=1; j<=edgelength; j++)
        {
            if(map[i][j]==0)
            {
                for(int k=1; k<=edgelength; k++)
                {
                    insert(sign,i,j,k);
                    sign += 4;
                }
            }
            else
            {
                insert(sign,i,j,map[i][j]);
                sign += 4;
            }
        }
}
void removec(int x)
{
    //errorlog.Add("remove"+x.ToString());
    int i, j;
    lists[0].sum--;
    lists[lists[x].left].right= lists[x].right;
    lists[lists[x].right].left = lists[x].left;
    for (i = lists[x].down; i != x; i = lists[i].down) for (j = lists[i].right; j != i; j = lists[j].right)
        {
            lists[lists[j].down].up = lists[j].up;
            lists[lists[j].up].down = lists[j].down;
            lists[lists[j].column].sum--;
        }
}
void resumec(int x)
{
    //errorlog.Add("resume" + x.ToString());
    int i, j;
    lists[0].sum++;
    for (i = lists[x].up; i != x; i = lists[i].up) for (j = lists[i].left; j != i; j = lists[j].left)
        {
            lists[lists[j].down].up = j;
            lists[lists[j].up].down = j;
            lists[lists[j].column].sum++;
        }
    lists[lists[x].left].right = x;
    lists[lists[x].right].left = x;
}
int dance(int x)
{
    if (lists[0].right == 0)
    {
        return 1;
    }
    else
    {
        int min = 999999, minn = 1 ;
        for (int i = lists[0].right; i != 0; i = lists[i].right)
          if (lists[i].sum< min)
            {
                min = lists[i].sum;
                minn = i;
            }
        removec(minn);
        for (int i = lists[minn].down; i != minn; i = lists[i].down)
        {
            ans[x] = i;
            for (int j = lists[i].right; j != i; j = lists[j].right) removec(lists[j].column);
            if (dance(x + 1)==1) return 1;
            for (int j = lists[i].left; j != i; j = lists[j].left) resumec(lists[j].column);
        }
        resumec(minn);
        return 0;
    }
}
bool solve()
{
    makeup();
    if (dance(0) == 1)
    {
        for (int i = 0; i < edgelength * edgelength; i++)
        {
            solvedmap[lists[ans[i]].x][lists[ans[i]].y] = lists[ans[i]].num;
        }
        return true;
    }
    return false;
}
int main()
{
  freopen("sudoku.in","r",stdin);
  freopen("sudoku.out","w",stdout);
  for(int i=1;i<=edgelength;i++)for(int j=1;j<=edgelength;j++)
  {
    scanf("%d",&map[i][j]);
  }
  solve();
  for(int i=1;i<=edgelength;i++)
  {
    for(int j=1;j<=edgelength;j++)printf("%d ",solvedmap[i][j]);
    cout<<endl;
  }
}
