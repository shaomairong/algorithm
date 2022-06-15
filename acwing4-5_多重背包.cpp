f[i][j] = max(f[i][j], f[i - 1][j - k * v[i]] + k * w[i]);  
//---------------朴素三重循环：时间复杂度 O(n*v*s)
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 110;
int v[N], w[N], s[N];
int f[N][N];
int n, m;
int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i ++) cin >> v[i] >> w[i] >> s[i];
    for(int i = 1; i <= n; i ++){//枚举背包
        for(int j = 1; j <= m; j ++){//枚举体积
            for(int k = 0; k <= s[i]; k ++){
                if(j >=  k * v[i]){
                    f[i][j] = max(f[i][j], f[i - 1][j - k * v[i]] + k * w[i]);
                }
            }
        }
    }
    cout << f[n][m] << endl;
    return 0;
}

//------------------------二进制优化
#include <bits/stdc++.h>
using namespace std;
const int N = 11 * 1000 + 10, M = 2010;
//这里N表示按照每一种的数量分组出来是log(2000)组 ，还要乘上1000种
//log 2000 = ? 2的10次方是1024，2的11次方是2048,所以也就是11左右
int v[N], w[N];
int f[M];
int main()
{
    int  n, m;
    scanf("%d %d", &n, &m);
    int cnt = 0;     // 将物品重新分组后的顺序
    for (int i = 1; i <= n; i ++)
    {
        int a, b, s;    // a 体积, b 价值, s 每种物品的个数
        scanf("%d %d %d", &a, &b, &s);
        int k = 1;   // 二进制拆分 打包时每组中有 k 个同种物品
        while (k <= s)  // 即y总说的: 最后一组的物品个数 < 2^(n+1)   1 2 4 8 16 ... 2^n 2^(n+1)
        {
            cnt ++;
            v[cnt] = a * k;  // 每组的体积
            w[cnt] = b * k;  // 每组的价值
            s -= k;
            k *= 2;  // 注意是 k * 2，每次增长一倍，不是k * k
        }
        if (s > 0)   // 二进制拆分完之后 剩下的物品个数分为新的一组
        {
            cnt ++;
            v[cnt] = a * s;
            w[cnt] = b * s;
        }
    }
    n = cnt;  //所有的组数即为 01背包中的物品个数
    // 写01背包模板
    for (int i = 1; i <= n; i ++)
        for (int j = m; j >= v[i]; j --)
           f[j] = max(f[j], f[j - v[i]] + w[i]);
    printf("%d", f[m]);
    return 0;
}