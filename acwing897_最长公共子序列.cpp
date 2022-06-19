状态表示
    集合：所有在A[1…i]中出现过且在B[1…j]中也出现过的子序列
    属性：Max
状态计算（划分子集）
   1： 所有在A[1…i−1]中出现过且在B[1…j]中也出现过的子序列，最大长度为f[i−1][j]
   2： 所有在A[1…i]中出现过且在B[1…j−1]中也出现过的子序列，最大长度为f[i][j−1]
   3：当A[i]==B[j]时,划分多一个子集 所有在A[1…i−1]中出现过且在B[1…j−1]中也出现过的子序列，最大长度为f[i−1][j−1]+1
   4： a[i]不在，b[j]不在，max=f[i−1][j−1]，在计算时这种情况包含在1，2中
#include <iostream>
using  namespace  std;
const int N  = 1e3+10;
int n,m;
char a[N],b[N];
int dp[N][N];
int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    scanf("%d%d%s%s",&n,&m,a+1,b+1);
    // cin>>n>>m>>a+1>>b+1;
    for(int i  = 1;i<=n;++i){
        for(int j = 1;j<=m;++j){
            dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            if(a[i]==b[j]) dp[i][j] = max(dp[i][j],dp[i-1][j-1]+1);
        }
    }
    cout<<dp[n][m]<<endl;
}