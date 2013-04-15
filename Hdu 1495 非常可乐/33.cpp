#include <stdio.h>
#include <math.h>
#include <queue>
#include <cstring>
using namespace std;

struct Node
{
    int s, n, m, ti;
}info;

int S, N, M, hash[105][105][105];

inline bool legal( Node t )
{
    int cnt= 0;
    if( t.s== S/ 2 )
    {
        cnt++;
    }
    if( t.n== S/ 2 )
    {
        cnt++;
    }
    if( t.m== S/ 2 )
    {
        cnt++;
    }
    if( cnt== 2 )
    {
        return true;
    }
    return false;
}

bool BFS( int &ans )
{
    queue< Node >q;
    info.s= S, info.m= 0, info.n= 0, info.ti= 0;
    hash[S][0][0]= 0;
    q.push( info );
    while( !q.empty() )
    {
        Node pos= q.front();
        q.pop();
        if( legal( pos ) )
        {
            ans= pos.ti;
            return true;
        }
        if( pos.s> 0 )
        {
            if( pos.n< N )
            {
                int temp= min( pos.s, N- pos.n );
                info.s= pos.s- temp;
                info.n= pos.n+ temp;
                info.m= pos.m;
                info.ti= pos.ti+ 1;
                if( pos.ti+ 1< hash[info.s][info.n][info.m] )
                {
                    hash[info.s][info.n][info.m]= pos.ti;
                    q.push( info );
                }
            }
            if( pos.m< M )
            {
                int temp= min( pos.s, M- pos.m );
                info.s= pos.s- temp;
                info.m= pos.m+ temp;
                info.n= pos.n;
                info.ti= pos.ti+ 1;
                if( pos.ti+ 1< hash[info.s][info.n][info.m] )
                {
                    hash[info.s][info.n][info.m]= pos.ti;
                    q.push( info );
                }
            }
        }
        if( pos.n> 0 )
        {
            if( pos.s< S )
            {
                int temp= min( pos.n, S- pos.s );
                info.s= pos.s+ temp;
                info.n= pos.n- temp;
                info.m= pos.m;
                info.ti= pos.ti+ 1;
                if( pos.ti+ 1< hash[info.s][info.n][info.m] )
                {
                    hash[info.s][info.n][info.m]= pos.ti;
                    q.push( info );
                }
            }
            if( pos.m< M )
            {
                int temp= min( pos.n, M- pos.m );
                info.n= pos.n- temp;
                info.m= pos.m+ temp;
                info.s= pos.s;
                info.ti= pos.ti+ 1;
                if( pos.ti+ 1< hash[info.s][info.n][info.m] )
                {
                    hash[info.s][info.n][info.m]= pos.ti;
                    q.push( info );
                }
            }
        }
        if( pos.m> 0 )
        {
            if( pos.s< S )
            {
                int temp= min( pos.m, S- pos.s );
                info.s= pos.s+ temp;
                info.m= pos.m- temp;
                info.n= pos.n;
                info.ti= pos.ti+ 1;
                if( pos.ti+ 1< hash[info.s][info.n][info.m] )
                {
                    hash[info.s][info.n][info.m]= pos.ti;
                    q.push( info );
                }
            }
            if( pos.n< N )
            {
                int temp= min( pos.m, N- pos.n );
                info.m= pos.m- temp;
                info.n= pos.n+ temp;
                info.s= pos.s;
                info.ti= pos.ti+ 1;
                if( pos.ti+ 1< hash[info.s][info.n][info.m] )
                {
                    hash[info.s][info.n][info.m]= pos.ti;
                    q.push( info );
                }
            }
        }
    }
    return false;
}

int main()
{
    freopen("in.in","r",stdin);
    freopen("out2.out","w",stdout);
    while( scanf( "%d %d %d", &S, &N, &M ), S| N| M )
    {
        if( S& 1 )
        {
            printf( "NO\n" );
            continue;
        }
        int ans;
        memset( hash, 0x7f, sizeof( hash ) );
        if( BFS( ans ) )
        {
            printf( "%d\n", ans );
        }
        else
        {
            puts( "NO" );
        }
    }
    return 0;
}
