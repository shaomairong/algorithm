        f[i][j] = max(f[i][j], f[i - 1][j - v[i][k]] + w[i][k]);
#include <iostream>
using  namespace  std;
const int N = 110;
int n,m;
int w[N][N]; 
int v[N][N];
int s[N]; //记录每一组的物品数量
int dp[N][N];
int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i = 1;i<=n;++i){
        cin>>s[i];
        for(int j = 1;j<=s[i];++j){
            cin>>w[i][j] >> v[i][j];
        }
    }
    for(int i = 1;i<=n;++i){//从前往后枚举每一组物品
        for(int j = 1;j<=m;++j){ //从大到小枚举每个体积
            for(int k = 1;k<=s[i];++k){ //选择第i组中的哪一个呢？max
                dp[i][j] = max(dp[i][j],dp[i-1][j]) ; //1)不选第i个物品
                if(j>=w[i][k]){ //2）选第i个物品但要j>=w[i][k]才能选
                    dp[i][j] = max(dp[i][j],dp[i-1][j-w[i][k]] + v[i][k]);
                }
            }
        }
    }
    cout<<dp[n][m]<<endl;
    return  0;
}

//-----------空间优化
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 110;
int f[N];
int v[N][N], w[N][N], s[N];
int n, m;
int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i ++){
        cin >> s[i];//第i组物品的数量
        for(int j = 1; j <= s[i]; j ++){//依次读入第i组第j个物品的体积和价值
            cin >> v[i][j] >> w[i][j];
        }
    }
    for(int i = 1; i <= n; i ++){
        for(int j = m; j >= 1; j --){
            for(int k = 1; k <= s[i]; k ++){
                if(j >= v[i][k]){
                    f[j] = max(f[j], f[j - v[i][k]] + w[i][k]);
                }
            } 
        }
    }
    cout << f[m] << endl;
    return 0;
}