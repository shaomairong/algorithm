#include <iostream>
#include <algorithm>
using  namespace  std;
const int N = 1010;
int n,m;
char a[N],b[N];
int dp[N][N];
int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    scanf("%d%s",&n,a+1);
    scanf("%d%s",&m,b+1); //下标1开始存储字符串
    for(int i = 0;i<=m;++i) dp[0][i] = i; //边界情况1:如果a初始长度是0，那么只能用插入操作让a变成b
    for(int i = 0;i<=n;++i) dp[i][0] = i ; //边界情况2:如果b的初始长度是0，那么只能用删除操作让a变成b
    for(int i = 1;i<=n;++i){
        for(int j = 1;j<=m;++j){
            dp[i][j]  = min(dp[i-1][j],dp[i][j-1]);
            if(a[i] ==b[i]) dp[i][j] = min(dp[i][j],dp[i-1][j-1]);
            else dp[i][j] = min(dp[i][j],dp[i-1][j-1]+1);
        }
    }
    cout<<dp[n][m]<<endl;
    return  0;
}