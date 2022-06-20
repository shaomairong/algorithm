#include <iostream>
#include <algorithm>
#include <cstring>
using  namespace  std;
const int N = 15,M = 1010;
int n,m; //n是字符串个数，m是询问次数
int dp[N][N];
char str[M][N];
int edit_distance(char a[],char b[]){
    int la = strlen(a+1),lb = strlen(b+1); //容易忽视的一步，字符串是从下标1开始存储的
    for(int i = 1;i<=la;++i) dp[i][0]  = i;
    for(int i = 1;i<=lb;++i) dp[0][i]  = i;
    
    for(int i = 1;i<=la;++i){
        for(int j = 1;j<=lb;++j){
            dp[i][j] = min(dp[i-1][j]+1,dp[i][j-1]+1);
            if(a[i] == b[j])  dp[i][j] = min(dp[i][j],dp[i-1][j-1]);
            else dp[i][j] = min(dp[i][j] ,dp[i-1][j-1]+1);
        }
    }
    return dp[la][lb];
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i = 0;i<n;++i) scanf("%s",str[i]+1); //读入n个字符串,字符串从字符数组下标1开始存储方便
    while (m--){
        char s[N];
        int limit;
        scanf("%s%d",s+1,&limit);
        int res  = 0;
        for(int i = 0;i<n;++i){
            if(edit_distance(str[i],s) <= limit) ++res;
            //注：这里只能传递str[i]和s然后函数里面计算的时候从str[i]+1和s+1开始计算字符长度
            //传递str[i]+1和s+1会出错
        }
        printf("%d\n",res);
    }
    return  0;
}