#include<stdio.h>
main()
{
      freopen("stu.in","rt+",stdin);  
      freopen("stu.out","wt+",stdout);
      struct student
      {
             int num;
             char name[20];
             float degree;
      }a;
      scanf("%d %c %f ",&a.num,a.name[1],&a.degree);
      printf("%d %c %f ",a.num,a.name[1],a.degree);
}
      
      
      
      

