#include <iostream>
using  namespace  std;

const int N = 1e5+10,M=1e6+10;
int n,m;
char  p[N],s[M ];
int ne[N];
//比如:abababab的next数组值手动计算就是:00123456
int main(){
    cin>>n >>p+1>>m>>s+1; //下标从1开始存储
    //1)求next过程:next[1]=0
    for(int i =  2,j=0;i<=n;++i){
        while (j && p[i]!=p[j+1]) j = ne[j];
        if(p[i] == p[j+1] ) ++j;
        ne[i] = j;
    }
    //2)匹配过程
    for(int i = 1,j = 0;i<=m;++i){  //i从1开始，j从0开始
        while (j && s[i]!=p[j+1]) j = ne[j];
        if(s[i] == p[j+1]) ++j;
        if(j == n){ //匹配成功
            //匹配成功了,输出起始位置
            printf("%d ",i-n);
            j = ne[j];//如果还需要下一次匹配就j=ne[j]
        }
    }
    return  0;
}