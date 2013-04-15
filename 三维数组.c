#include<stdio.h>
main()
{
    int s[3][3][3]={{{0,0,0},{0,0,0},{0,0,0}},{{0,0,0},{0,0,0},{0,0,0}},{{0,0,0},{0,0,0},{0,0,0}}};
    int x,y,z;
    for(x=0;x<=2;x++)
      {
      for(y=0;y<=2;y++)
       {
       for(z=0;z<=2;z++)
        printf("%d,",s[x][y][z]);
       printf(" ");
       }
      printf("\n");
      }
    
    getchar();
    getchar();
}
    
