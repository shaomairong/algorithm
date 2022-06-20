
f[i][j] 的状态表示: i 为 从 1 ~ i 中选 总体积恰好为 j
 f[i][j] 的性质 : 数量;
 f[i][j] 的计算: 第i个物品选k个;
f[i][j] = f[i-1][j] + f[i-1][j-i] + f[i-1][j - i*2] + ....f[i-1][j-i*s];
f[i][j - i] =         f[i-1][j-i] + f[i-1][j - i*2] + ....f[i-1][j-i*s];
合并一下 f[i][j] = f[i-1][j] + f[i][j-i];
//方法1：-----------------转换成完全背包问题
#include <iostream>
using  namespace  std;
const int N = 1e4 + 10;
int n;
int dp[N][N];
const int mode =  1e9+7;
int main(){
    cin>>n;
    for(int i = 0;i<=n;++i) dp[i][0] = 1; //base case : 前i个数任意选凑成0的方案数是1，不选就行了
    for(int i = 1;i<=n;++i){
        for(int j = 1;j<=n;++j){
            //状态转移方程:dp[i][j] = dp[i-1][j] + dp[i][j-i]
            //只能当j>=i才会有后面那一步
            if(j>=i){
                dp[i][j] = (dp[i-1][j] + dp[i][j-i]) % mode;
            }else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    cout<<dp[n][n]<<endl;
    return  0;
}

//方法2：  dp[i][j]表示：所有总和是i且恰好由j个数表示的方案
#include <iostream>
using  namespace  std;
const int N = 1010;
const int mode = 1e9+7;
int dp[N][N];
int n;
int main(){
    cin>>n;
    //难想的base case ,dp[i][j]的含义是:所有总和是i,并且恰好表示为j个数的和的方案
    dp[0][0] = 1;//总和为0，用0个数去表示，方案是1（不选那就是选0个，所以是一种方案）
    #if 0 
    for(int i = 1;i<=n;++i){   
        for(int j = 1;j<=i;++j){  
            dp[i][j] = (dp[i-1][j-1] + dp[i-j][j])  % mode; 
        }
    }
    #endif 
    for(int i = 1;i<=n;++i){
        for(int j = 1;j<=i;++j){  //zr写法
            if(i>=j){
                dp[i][j] = (dp[i-1][j-1] + dp[i-j][j] ) % mode;
            }else {
                dp[i][j]  = dp[i-1][j-1];
            }
        }
    }
    int sum = 0;
    for(int i = 1;i<=n;++i){
        sum = (sum + dp[n][i])  % mode; 
    }
    cout<<sum  <<endl;
    return  0;
}