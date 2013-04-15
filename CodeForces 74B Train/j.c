#include<stdio.h>
#include<string.h>
int main()
{
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    int n,con,cond,sto,i,l;
    char s[2000];
    scanf("%d%d%d",&n,&sto,&con);
    if(sto==con||n==1)
    {
        printf("Controller 1");
        return 0;
    }
    scanf("%s%s",s,s);
    if(s[0]=='h')cond=-1;
    else cond=1;
    scanf("%s",s);
    l=strlen(s);
    for(i=0;i<l;i++)
    {
        if(s[i]=='0'&&i>0&&s[i-1]=='1')
        {
            if(con==1)sto=n;
            else if(con==n)sto=1;
            else if(cond==1)sto=1;
            else sto=n;
        }
        else if(s[i]=='0')
        {
            if(con>sto&&sto!=1)sto--;
            else if(con<sto&&sto!=n)sto++;
        }
        else sto=55;
        con+=cond;
        if(con==1&&cond==-1)cond=1;
        else if(con==n&&cond==1)cond=-1;
        if(sto==con)
        {
            //printf("%d %d",con,sto);
            printf("Controller %d",i+1);
            return 0;
        }
    }
    printf("Stowaway");
    return 0;
}
