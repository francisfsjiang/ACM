#include<iostream>
#include<cstdio>
#include<vector>
#define bugs(a,b) cout<<#a<<" ";for(int zz=0;zz<=b;zz++)cout<<a[zz]<<" ";cout<<endl;
using namespace std;
int clock[9];
int temp[9];
int mo[9][7]=
{
{4,1,2,4,5},//1
{3,1,2,3},//2
{4,2,3,5,6},//3
{3,1,4,7},//4
{5,2,4,5,6,8},//5
{3,3,6,9},//6
{4,4,5,7,8},//7
{3,7,8,9},//8
{4,5,6,8,9}//9
};
int step[9];
int miner;
bool check()
{
    for(int i=0;i<9;i++)temp[i]=clock[i];

    for(int i=0;i<9;i++)
    {
        for(int j=1;j<=mo[i][0];j++)
        {
            temp[mo[i][j]-1]+=step[i];
        }
    }
    //bugs(temp,9);
    for(int i=0;i<9;i++)if(temp[i]%4!=0)return false;
    return true;
}
vector<int> result(50);
void search(int x)
{
    if(x==9)
    {

//bugs(step,9);
        if(check())
        {
            int sum=0;
            for(int i=0;i<9;i++)sum+=step[i];
            //cout<<sum<<endl;
            if(sum<result.size())
            {
                //cout<<sum<<endl;
                result.clear();
                miner=sum;
                for(int i=0;i<9;i++)
                {
                    for(int j=0;j<step[i];j++)result.push_back(i);
                }
            }
        }
        return;
    }
    for(int i=0;i<4;i++)
    {
        step[x]=i;
        search(x+1);
    }
}
int main()
{
    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);
    for(int i=0;i<9;i++)cin>>clock[i];
    //for(int i=0;i<9;i++)cout<<clock[i]<<" ";
    //cout<<endl;
    search(0);
    for(int i=0;i<result.size();i++)cout<<result[i]+1<<" ";
    return 0;
}
