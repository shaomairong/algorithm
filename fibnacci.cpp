/*
 *  计算fib数列的方法:
 *  1:直接递归,垃圾算法
 *  2:循环计算 0(N)
 *  3:记忆化递归 0(N)
 *
 * */
#include <iostream>
using  namespace std;
#define  M 45
int fibarray[1000]={0};
int fib(int n)
{
    int a[1000]={0};
    a[0 ]=0;
    a[1]=1;
    for(int i=2;i<=n;i++)
    {
        a[i]=a[i-1]+a[i-2];
    }
    return a[n];

}
int fib2(int n)
{
    if(n==2 || n==1) return 1;
    else
        return  fib2(n-1)+fib2(n-2);
}
int fib3(int n)
{
    if(n==0) return  fibarray[0]=0;
    if(n==1) return  fibarray[1]=1;  //初始二种情况
    if(fibarray[n]!=0) return  fibarray[n];  //如果已经计算了,就直接返回fib[b]
    return  fibarray[n]= fib3(n-1)+fib3(n-2); //记忆化递归,计算了之后就把他存放在了fibarray[n]中,
    // 之后要用的话,如果fibarray[n]不为0直接返回,不需要计算了
    
}


int main()
{

   // std::cout<<"hello world"<<std::endl;
   cout<<"fib="<<fib(M)<<endl;

    cout<<"fib3="<<fib3(M)<<endl;
    cout<<"fib2="<<fib2(M)<<endl;


    return 0;
}
