#include<stdio.h>
int main()
{
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    char s[10];
    int data[4][4];
    int i,j,k,sumofx=0,sumof0=0,sign1,sign2;
    for(i=1;i<=3;i++)
    {
        scanf("%s",s);
        for(j=1;j<=3;j++)
        {
            if(s[j-1]=='X')
            {
                data[i][j]=1;
                sumofx++;
            }
            else if(s[j-1]=='0')
            {
                data[i][j]=2;
                sumof0++;
            }
            else data[i][j]=0;
        }
    }
    sign1=0;
    sign2=0;
    for(i=1;i<=3;i++)
    {
        if(data[i][1]==data[i][2]&&data[i][1]==data[i][3]&&data[i][1]==1)sign1=1;
        else if(data[i][1]==data[i][2]&&data[i][1]==data[i][3]&&data[i][1]==2)sign2=1;
    }
    for(i=1;i<=3;i++)
    {
        if(data[1][i]==data[2][i]&&data[1][i]==data[3][i]&&data[1][i]==1)sign1=1;
        else if(data[1][i]==data[2][i]&&data[1][i]==data[3][i]&&data[1][i]==2)sign2=1;
    }
    if(data[1][1]==data[2][2]&&data[1][1]==data[3][3]&&data[1][1]==1)sign1=1;
    else if(data[1][1]==data[2][2]&&data[1][1]==data[3][3]&&data[1][1]==2) sign2=1;
    if(data[3][1]==data[2][2]&&data[3][1]==data[1][3]&&data[3][1]==1)sign1=1;
    else if(data[3][1]==data[2][2]&&data[3][1]==data[1][3]&&data[3][1]==2)sign2=1;
    if(sumof0>sumofx||sumofx>sumof0+1||(sign1==1&&sumof0+1!=sumofx)||(sign2==1&&sumof0!=sumofx))
    {
        printf("illegal");
        return 0;
    }
    //printf
    if(sign1==1)printf("the first player won");
    else if(sign2==1)printf("the second player won");
    else if((sumofx+sumof0)==9) printf("draw");
    else
    {

        if(sumofx>sumof0)printf("second");
        else if(sumofx<sumof0)printf("first");
        else printf("first");
    }
    return 0;
}
