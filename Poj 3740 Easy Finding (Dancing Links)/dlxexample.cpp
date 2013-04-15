    #include<cstdio>
    #include<vector>
    #include<cstring>
    #include<algorithm>
    using namespace std;
    #define maxn 611
    #define maxm 6611
    int n,m,t,size;
    int U[maxm],D[maxm],L[maxm],R[maxm],C[maxm];//上，下，左，右，列
    int H[maxn],S[maxn];//当前所在行，列中1个数
    void link(int r,int c)
    {
        ++S[C[size]=c];
        D[size]=D[c];
        U[D[c]]=size;
        U[size]=c;
        D[c]=size;
        if(H[r]<0) H[r]=L[size]=R[size]=size;
        else
        {
            R[size]=R[H[r]];
            L[R[size]]=size;
            L[size]=H[r];
            R[H[r]]=size;
        }
        size++;
    }
    void remove(int c)
    {
        R[L[c]]=R[c],L[R[c]]=L[c];
        for(int i=D[c];i!=c;i=D[i])
            for(int j=R[i];i!=j;j=R[j])
                U[D[j]]=U[j],D[U[j]]=D[j],--S[C[j]];
    }
    void resume(int c)
    {
        R[L[c]]=L[R[c]]=c;
        for(int i=U[c];i!=c;i=U[i])
            for(int j=L[i];j!=i;j=L[j])
                U[D[j]]=D[U[j]]=j,++S[C[j]];
    }
    bool dance(int k)
    {
        int i,j,tmp,c;
        if(!R[0])
        {
            puts("Yes, I found it");
            return 1;
        }
        for(tmp=maxn,i=R[0];i;i=R[i])
            if(S[i]<tmp) tmp=S[c=i];
        remove(c);
        for(i=D[c];i!=c;i=D[i])
        {
            for(j=R[i];j!=i;j=R[j]) remove(C[j]);
            if(dance(k+1)) return 1;
            for(j=L[i];j!=i;j=L[j]) resume(C[j]);
        }
        resume(c);
        return 0;
    }
    int main()
    {
        freopen("in.in","r",stdin);
        freopen("out.out","w",stdout);
        int i,j,k;
        while(scanf("%d%d",&n,&m)!=EOF)
        {
            for(i=0;i<=m;i++)
            {
                S[i]=0;
                D[i]=U[i]=i;
                L[i+1]=i,R[i]=i+1;
            }
            R[m]=0;
            size=m+1;
            for(i=1;i<=n;i++)
            {
                H[i]=-1;
                for(j=1;j<=m;j++)
                {
                    scanf("%d",&k);
                    if(k) link(i,j);
                }
            }
            for(i=0;i<size;i++)printf("%2d ",U[i]);
            printf("\n");
            for(i=0;i<size;i++)printf("%2d ",D[i]);
            printf("\n");
            for(i=0;i<size;i++)printf("%2d ",L[i]);
            printf("\n");
            for(i=0;i<size;i++)printf("%2d ",R[i]);
            printf("\n");
            for(i=0;i<size;i++)printf("%2d ",C[i]);
            printf("\n");
            if(!dance(0)) puts("It is impossible");
        }
        return 0;
    }
