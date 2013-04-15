#include<stdio.h>
#include<string.h>
int main()
{
    freopen("vigenere.in","r",stdin);
    freopen("vigenere.out","w",stdout);
    int bb(int x,int y);
    int i,j,k,sign,temp,pos2,l1,l2;
    int x,y;
    char s1[120],s2[120];
    int result[120];
    scanf("%s%s",s2,s1);
    l1=strlen(s1);
    l2=strlen(s2);
    pos2=0;
    for(i=0;i<l1;i++)
    {
        if(s1[i]>='a'&&s1[i]<='z')
        {
            sign=1;
            x=s1[i]-'a';
        }
        else
        {
            sign=2;
            x=s1[i]-'A';
        }
        if(s2[pos2]>='A'&&s2[pos2]<='Z') y=s2[pos2]-'A';
        else y=s2[pos2]-'a';
        pos2++;
        if(pos2>=l2)pos2=0;
        temp=bb(x,y);
        //printf("x=%d  y=%d  temp=%d\n",x,y,temp);
        if(sign==1)printf("%c",temp+'a');
        else printf("%c",temp+'A');
    }
    return 0;
}

int bb(int x,int y)
{
    if(x>=y)return x-y;
    else return x+26-y;
}
