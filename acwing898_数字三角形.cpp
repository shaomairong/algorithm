dp[i][j] = arr[i][j] + max(dp[i+1][j],dp[i+1][j+1] 
//---------------版本1：
#include <iostream>
using  namespace  std;
const int N = 510;
int arr[N][N];
int dp[N][N];
int n;
int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i = 1;i<=n;++i){
        for(int j = 1;j<=i;++j){
            cin>>arr[i][j];
        }
    }
    for(int i = 1;i<=n;++i){
        dp[n][i] = arr[n][i]; //base case 
    }
    for(int i = n-1;i>=1;--i){
        for(int j = 1;j<=i;++j){
            dp[i][j] = arr[i][j] +max(dp[i+1][j],dp[i+1][j+1]);
        }
    }
    cout<<dp[1][1]<<endl;
    return  0;
}
//版本2------------------空间优化
#include <iostream>
using  namespace  std;
const int N = 510;
int arr[N][N];
int dp[N];
int n;
int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i = 1;i<=n;++i){
        for(int j = 1;j<=i;++j){
            cin>>arr[i][j];
        }
    }
    for(int i = 1;i<=n;++i){
        dp[i] = arr[n][i]; //base case
    }
    for(int i = n-1;i>=1;--i){
        for(int j = 1;j<=i;++j){
            dp[j] = arr[i][j] + max(dp[j],dp[j+1]);
        }
    }
    cout<<dp[1]<<endl;
    return  0;
}