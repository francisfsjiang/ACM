#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

struct edge{
    int x, y, v;
    bool operator <(const edge &a) const{
        return v > a.v;
    }
};

const int N = 100002;
edge e[N];
bool b[N];
int f[N];

int Find(int x){
    if(f[x] == -1) return x;
    return f[x] = Find(f[x]);
}

void Union(int x, int y){
    f[Find(x)] = Find(y);
}

long long Kruscla(int n){ //±‰–Œ
    sort(e, e +n);
    long long sum = 0;
    memset(f, -1, sizeof(f));
    for(int i = 0; i < n; i ++){
        int x = Find(e[i].x);
        int y = Find(e[i].y);

        if(b[x] && b[y]) {
            sum += e[i].v;
            continue;
        }
        if(b[x] || b[y]) b[x] = b[y] = 1;
        Union(x,y);
    }
    return sum ;
}

int main(){
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    int T, n, m, x;
    scanf("%d", &T);
    while(T--){
        scanf("%d%d", &n, &m);
        for(int i = 0; i < n-1; i ++)
            scanf("%d%d%d", &e[i].x, &e[i].y, &e[i].v);
        memset(b, 0, sizeof(b));
        for(int i = 0; i < m; i ++){
            scanf("%d", &x);
            b[x] = 1;
        }
        printf("%I64d\n", Kruscla(n-1));
    }
}
