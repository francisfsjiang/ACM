#include<stdio.h>
main()
{
long a,b,d;
char c;
printf("ÇëÊäÈëËãÊ½£¬ÀýÈç10/20\n ");
scanf("%ld%c%ld",&a,&c,&b);
if(c=='+')                                  //+
 {
 d=a+b;
 if(a>=2147483647) printf("The number is too large,please press again.\n");
 else printf("=%ld.",d);
 }
if(c=='-')                                 //-
 { 
 d=a-b;
 printf("=%ld.",d);
 }
if(c=='*')                                 //*
 {
 d=a*b;
 printf("=%ld.",d);
 }
if(c=='/')                                 ///
 {
 d=a/b;
 printf("=%ld.",d);
 }
if(c!='+'&&c!='-'&&c!='*'&&c!='/')
 printf("=Error.");
getchar();
getchar();
}
