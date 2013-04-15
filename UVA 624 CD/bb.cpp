#include <stdio.h>
#include <string.h>

#define W 10005

int c[W], l[25];
bool p[25][W];

int main()
{
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    int w, n;
    while(~scanf("%d", &w))
    {
        scanf("%d", &n);
        for(int i = 1; i <= n; i++)
            scanf("%d", &l[i]);

        memset(c, 0, sizeof(c));
        memset(p, 0, sizeof(p));

        for(int i = n; i; i--)
        for(int j = w; j >= l[i]; j--)
        {
            if(c[j] < c[j - l[i]] + l[i])
            {
                c[j] = c[j - l[i]] + l[i];
                p[i][j] = 1;
            }
        }
        for(int i = 1, j = w; i <= n; i++)
            if(p[i][j])
            {
                printf("%d ", l[i]);
                j -= l[i];
            }
        printf("sum:%d\n", c[w]);
    }
    return 0;
}
