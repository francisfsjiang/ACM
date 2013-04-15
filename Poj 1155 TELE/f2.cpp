    #include<stdio.h>
    #include<string.h>
    #include<vector>
    using namespace std;

    const int maxn=3010;
    const int INF=(1<<28);

    int N,M;
    struct Node{
        int v;
        int c;
    };
    vector<Node>map[maxn];
    int val[maxn];
    int dp[maxn][maxn];

    int Max(int a,int b){
        if(a<b)return b;
        return a;
    }

    int DFS(int u)
    {

        int i,j,k,v;
        int sum=0;
        if(map[u].size()==0)
        {
            dp[u][1]=val[u];
            return 1;
        }
        dp[u][0]=0;
        for(i=0;i<map[u].size();i++)
        {

            v=map[u][i].v;
            int num=DFS(v);
            sum+=num;
            printf("%d %d\n",v,sum);
            for(j=sum;j>=0;j--)
            {
                for(k=0;k<=num && k<=j;k++)
                {
                    dp[u][j]=Max(dp[u][j],dp[u][j-k]+dp[v][k]-map[u][i].c);
                    //printf("dp[%d][%d]=maxs(dp[%d][%d],dp[%d][%d]+dp[%d][%d]-%d);==%d\n",u,j,u,j,u,j-k,v,k,map[u][i].c,dp[u][j]);
                }
            }
        }
        return sum;
    }

    int main()
    {
        freopen("in.in","r",stdin);
        freopen("out.out","w",stdout);
        int i,j;
        int K,a,b;
        Node tmp;
        while(scanf("%d%d",&N,&M)!=EOF)
        {
            for(i=0;i<=N;i++)
                map[i].clear();
            for(i=1;i<=N-M;i++)
            {
                scanf("%d",&K);
                for(j=0;j<K;j++)
                {
                    scanf("%d%d",&tmp.v,&tmp.c);
                    map[i].push_back(tmp);
                }
            }
            memset(val,0,sizeof(val));
            for(i=N-M+1;i<=N;i++)
                scanf("%d",&val[i]);
            for(i=0;i<maxn;i++)
                for(j=0;j<maxn;j++)
                    dp[i][j]=-INF;
            DFS(1);
            int ans=0;
            for(i=N;i>=0;i--)printf("%d ",dp[1][i]);
            printf("\n");
            for(i=N;i>=0;i--)
                if(dp[1][i]>=0)
                {
                    ans=i;
                    break;
                }
            printf("%d\n",ans);
        }
        return 0;
    }
