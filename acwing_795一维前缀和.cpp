#include <iostream>
using namespace std;
const int N = 1e6+10;
int n,m;//全部变量默认清0
int a[N],S[N]; //全局数组默认都是0
int main(){
    scanf("%d%d",&n,&m);
    for(int i =1;i<=n;++i){
    //下标从1开始的好处是s[0]就不用对应任何的变量了，就可以把s[0]定义为0
//处理边界时就好处了
        scanf("%d",&a[i]);
    }
    for(int i =1;i<=n;++i){
        S[i] = S[i-1]+a[i];
    }
    while (m--){
        int l,r;
        scanf("%d%d",&l,&r);
        printf("%d\n",S[r] - S[l-1]);
    }
    return  0;
}