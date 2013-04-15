#include<iostream>
#include<map>
#include<stdio.h>
#include<string.h>
using namespace std;
#define Inf 102
#define Max 1000000
char Date[Inf][Inf];
int dir0[6] = {100000,10000,1000,100,10,1};
int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
int r,c;
int fromx,fromy,endx,endy;
int begint,endt;
map < int , int > linkt;
bool Hash[Inf][Inf][25];
bool doxi = false;
int resout = -1;
int Qu[Max][4];

void date_in()
{
    int i;
    gets(Date[0]);
    for( i = 0 ; i < r ; ++i) gets(Date[i]);
    cin >> fromx >> fromy >> endx >> endy;
    begint = endt = 0;
    int num;
    for( i = 0 ; i < 6 ; ++i)
    {
        cin >> num;
        begint += num * dir0[i];
    }
    for( i = 0 ; i < 6 ; ++i)
    {
        cin >> num;
        endt += num * dir0[i];
    }
//    cout << begint << " " << endt << endl;
    memset(Hash , false ,sizeof(Hash));
    doxi = false;
    resout = -1;
}
void make_map()
{
    linkt[165243] = 1;
    linkt[163452] = 2;
    linkt[162534] = 3;
    linkt[164325] = 4;
    linkt[251643] = 5;
    linkt[253416] = 6;
    linkt[256134] =7;
    linkt[254361] =8;
    linkt[346152] =9;
    linkt[342561] =10;
    linkt[341625] =11;
    linkt[345216] =12;
    linkt[431652] =13;
    linkt[432516] =14;
    linkt[436125] =15;
    linkt[435261] =16;
    linkt[524316] =17;
    linkt[526143] =18;
    linkt[523461] =19;
    linkt[521634] =20;
    linkt[613425] =21;
    linkt[615234] =22;
    linkt[614352] =23;
    linkt[612543] =24;
}
void bfs()
{
    int Qu_b = 0;
    int Qu_e = 1;
    Qu[0][0] = begint;
    Qu[0][1] = 0;
    Qu[0][2] = fromx;
    Qu[0][3] = fromy;
    while( Qu_b < Qu_e)
    {
        int t = Qu[Qu_b][0];
        // South
//        cout << t << " " << Qu[Qu_b][1] << " ( " << Qu[Qu_b][2] << " ," << Qu[Qu_b][3] << " ) " << endl;
        if( Qu[Qu_b][2] + 1 < r)
        {
            int x = Qu[Qu_b][2] + 1;
            int y = Qu[Qu_b][3];
            int num = 0;
            num += t % 100;
            num += t % 10000 / 100 * 10000;
            num += t / 100000 * 100;
            num += t / 10000 % 10 * 1000;
            if( x == endx && y == endy && num == endt)
            {
                doxi = true;
                cout << Qu[Qu_b][1] + 1 << endl;
                return ;
            }
            if( !Hash[x][y][linkt[num]] && Date[x][y] != '#')
            {
                Hash[x][y][linkt[num]] = true;
                Qu[Qu_e][0] = num;
                Qu[Qu_e][1] = Qu[Qu_b][1] + 1;
                Qu[Qu_e][2] = x;
                Qu[Qu_e][3] = y;
//                cout <<" in1 : " << Qu[Qu_e][0] << " " << Qu[Qu_e][1] << " " << Qu[Qu_e][2] << " " << Qu[Qu_e][3] << endl;
                Qu_e++;
            }
        }
//        cout << " west " << endl;
        //West
        if( Qu[Qu_b][3] - 1 >= 0)
        {
            int x = Qu[Qu_b][2];
            int y = Qu[Qu_b][3] -1;
            int num = 0;
            num += t / 10000;
            num += ( t/ 100 % 100) * 100;
            num += ( t % 100 / 10) * 10000;
            num += ( t % 10) * 100000;
            if( x == endx && y == endy && num == endt)
            {
                doxi = true;
                cout << Qu[Qu_b][1] + 1 << endl;
                return ;
            }
            if( !Hash[x][y][linkt[num]] && Date[x][y] != '#')
            {
                Hash[x][y][linkt[num]] = true;
                Qu[Qu_e][0] = num;
                Qu[Qu_e][1] = Qu[Qu_b][1] + 1;
                Qu[Qu_e][2] = x;
                Qu[Qu_e][3] = y;
//                                cout <<" in2 : " << Qu[Qu_e][0] << " " << Qu[Qu_e][1] << " " << Qu[Qu_e][2] << " " << Qu[Qu_e][3] << endl;

                Qu_e++;
            }
        }
//        cout << " north " << endl;
        //north
        if( Qu[Qu_b][2] - 1 >= 0 )
        {
            int x = Qu[Qu_b][2] - 1;
            int y = Qu[Qu_b][3];
            int num = 0;
            num += t%100;
            num += t / 10000 * 100;
            num += t % 1000 / 100 * 100000;
            num += t % 10000 / 1000 * 10000;
            if( x == endx && y == endy && num == endt)
            {
                doxi = true;
                cout << Qu[Qu_b][1] + 1 << endl;
                return ;
            }
            if( !Hash[x][y][linkt[num]] && Date[x][y] != '#')
            {
                Hash[x][y][linkt[num]] = true;
                Qu[Qu_e][0] = num;
                Qu[Qu_e][1] = Qu[Qu_b][1] + 1;
                Qu[Qu_e][2] = x;
                Qu[Qu_e][3] = y;
//                cout <<" in 3: " << Qu[Qu_e][0] << " " << Qu[Qu_e][1] << " " << Qu[Qu_e][2] << " " << Qu[Qu_e][3] << endl;

                Qu_e++;
            }
        }
        // east;
//        cout << " east " << endl;
        if( Qu[Qu_b][3] + 1 < c)
        {
            int x = Qu[Qu_b][2];
            int y = Qu[Qu_b][3] + 1;
            int num = 0;
            num += t / 100000;
            num +=( t / 10000 )% 10 * 10;
            num += ( t / 100) % 100 * 100;
            num += ( t % 100) * 10000;
//            cout << num << endl;
            if( x == endx && y == endy && num == endt)
            {
//                cout << " jfakldj fadj " << endl;
                doxi = true;
                cout << Qu[Qu_b][1] + 1 << endl;
                return ;
            }
            if( !Hash[x][y][linkt[num]] && Date[x][y] != '#')
            {
                Hash[x][y][linkt[num]] = true;
                Qu[Qu_e][0] = num;
                Qu[Qu_e][1] = Qu[Qu_b][1] + 1;
                Qu[Qu_e][2] = x;
                Qu[Qu_e][3] = y;
//                cout <<" in4 : " << Qu[Qu_e][0] << " " << Qu[Qu_e][1] << " " << Qu[Qu_e][2] << " " << Qu[Qu_e][3] << endl;

                Qu_e++;
            }
        }
        Qu_b++;
    }
}
int main()
{
    freopen("in.in","r",stdin);
    freopen("out2.out","w",stdout);
    make_map();
    while( cin >> r >> c)
    {
        date_in();
        bfs();
        if( !doxi) cout << -1 << endl;
    }
    return 0;
}
