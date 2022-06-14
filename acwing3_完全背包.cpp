//---------------版本1：有对k的枚举行为,三重循环
#include <iostream>
using  namespace  std;
const int N = 1e4+10;
int v[N],w[N];
int dp[N][N];
int n,m;
int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i = 1;i<=n;++i){
        cin>>v[i]>>w[i];
    }
    for(int i = 1;i<=n;++i){
        for(int j = 1;j<=m;++j){
            for(int k = 0; k * v[i] <= j;++k){ //第i个物品可以选择多少个？选择的物品重量不能超过背包体积j
                dp[i][j] = max(dp[i][j],dp[i-1][j-k*v[i]] + k* w[i]);
            }
        }
    }
    cout<<dp[n][m]<<endl;
    return  0;
}
//-------------版本2：优化枚举行为，二重循环
dp[i][j]=dp[i-1][j-k*v[i]]+k*w[i] 
观察一下状态转移方程，将k展开看看： 
dp[i][j] = max(dp[i-1][j] , dp[i-1][j-v[i]]+w  , dp[i-1][j-2*v[i]]+2*w ....)
dp[i][j-v[i]] = max(        dp[i-1][j-v[i]] ,    dp[i-1][ j[2*[i]]+w       .....
发现dp[i][j]  = max(dp[i-1][j] , dp[i][j-v[i]] + w ) 
    完全背包二维 之所以只能正序更新，不能逆序更新是因为：f[i][j]=max(f[i−1][j],f[i][j−v[i]]+w[i]);
想求 f[i][j]，要先求f[i][j−v[i]]，两者都是f[i]，也就是在同一层，所以只能正序更新。
    01背包二维之所以 正序逆序都可以是因为：f[i][j]=max(f[i−1][j],f[i−1][j−v[i]]+w[i]);
想求f[i][j]，要先求f[i−1][j−v[i]]，前者是f[i]，后者是f[i - 1]，不在同一层，所以 正序逆序更新都可以。

// 完全背包：二维朴素写法
#include<iostream>
using namespace std;
const int N = 1010;
int n, m;
int v[N], w[N];
int f[N][N];
int main(){
    cin >> n >> m;
    for (int i = 1; i <= n; i ++ ) cin >> v[i] >> w[i];
    for (int i = 1; i <= n; i ++ )
        for (int j = 0; j <= m; j ++ ){ // 完全背包 二维 只能 正序更新, 01背包 二维 正序/逆序 更新 都可以
        // for (int j = m; j >= 0; j -- ){ // 完全背包 二维 逆序更新 会报错
            if (j < v[i]) f[i][j] = f[i - 1][j];
            else f[i][j] = max(f[i - 1][j], f[i][j - v[i]] + w[i]);
            // 01 背包：f[i][j] = max(f[i - 1][j], f[i - 1][j - v[i]] + w[i]);
        }
    cout << f[n][m] << endl;
    return 0;
}
//-----------------版本3：对空间进行优化
// 完全背包：一维空间优化写法, 将 以上代码 最终简写为如下：
// 注意 for (int j = v[i]; j <= m; j ++ ) 中 j 初始化为 v[j]，简化之前 j 初始化为 0
#include<iostream>
using namespace std;
const int N = 1010;
int n, m;
int v[N], w[N];
int f[N];
int main(){
    cin >> n >> m;
    for (int i = 1; i <= n; i ++ ) cin >> v[i] >> w[i];
    for (int i = 1; i <= n; i ++ )
        for (int j = v[i]; j <= m; j ++ ) // 完全背包 一维 只能 正序更新
        // 01背包 一维 只能 逆序更新: for (int j = m; j >= v[i]; j -- )
            f[j] = max(f[j], f[j - v[i]] + w[i]);
    cout << f[m] << endl; // f[n][m] ---> f[m]
    return 0;
}
