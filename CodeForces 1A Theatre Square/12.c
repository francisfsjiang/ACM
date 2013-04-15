
#include<iostream>
using namespace std;
int main(){
    __int64 n,m,a;
    cin>>n>>m>>a;
    __int64 sum=0;
    int flag1=0;
    int flag2=0;
    if(n%a)
         flag1=1;
    if(m%a)
         flag2=1;
    sum=(n/a+flag1)*(m/a+flag2);
    cout<<sum<<endl;
    return 0;
}
