//方法1：自下而上遍历
#include <iostream>
using namespace std;
const int N = 307;
int s[N];
int f[N][N];
int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        s[i] += s[i - 1];
    }
    for (int i = n; i >= 1; i--) {
        for (int j = i; j <= n; j++) {
            if (j == i) {
                f[i][j] = 0; //i==j时就是一堆石子，不用合并
                continue;
            }
            f[i][j] = 1e9;
            for (int k = i; k < j; k++) {
                f[i][j] = min(f[i][j], f[i][k] + f[k + 1][j] + s[j] - s[i - 1]);
            }
        }
    }
    cout << f[1][n] << endl;
    return 0;
}

//方法二：记忆化搜索
#include <iostream>
#include <cstring>
using namespace std;
const int N = 307;
int a[N], s[N];
int f[N][N];
// 记忆化搜索：dp的记忆化递归实现
int dp(int i, int j) {
    if (i == j) return 0; // 判断边界：如果i==j就是一堆石子不用合并
    int &v = f[i][j];
    if (v != -1) return v; //v!=-1表示已经计算过了存进表格了，可以直接返回了
    //没有计算，下面开始计算
    v = 1e8;
    for (int k = i; k <= j - 1; k ++)
        v = min(v, dp(i, k) + dp(k + 1, j) + s[j] - s[i - 1]);
        //易错点：这里是递归函数调用dp(i,k),而不是dp[i][k]
    return v;
}
int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        s[i] += s[i - 1] + a[i];
    }
    memset(f, -1, sizeof f);
    cout << dp(1, n) << endl;
    return 0;
}