#include <iostream>
#include <algorithm>
using namespace std;
typedef unsigned long long ULL; // 0 ~ 2^64 - 1, 溢出相当于取模
const int N = 100010, P = 131; // P 取 131 或 13331 为经验值
int n, m; // n字符串长度
char str[N];
// h[i] 存的是长度为 i 的前缀子字符串 的哈希值, p[i]存的是 P^i
ULL h[N], p[N];
ULL getHash(int l, int r) { // O(1)时间 计算字符串str 下标为[l, r] 的子字符串 哈希值
    // 注意 h[i] 存的是 字符串str 中 长度为 i 的 的 前缀 子字符串的 哈希值, i ~ [1, n]
    // // str 的下标范围是 [0, n - 1], 哈希表h[i]的下标 与 字符串str的下标 存在 1 的差值
    // return h[r + 1] - h[l - 1 + 1] * p[r - l + 1]; // h[r] - h[l - 1] 注意 下标 + 1
    // 如果程序一开始 str = ' ' + str, 或者 scanf("%s", str + 1)
    // 即 str 的有效字符下标 为 [1, n] 和 哈希表h[i]的有效下标 [1, n]对应, 不存在差值 1
    return h[r] - h[l - 1] * p[r - l + 1];
}
int main()
{
    scanf("%d%d", &n, &m);
    // O(n)预处理计算 n个前缀子字符串哈希值. h[i] 存的是长度为 i 的前缀子字符串 的哈希值
    // scanf("%s", str); // 这里 str, getHash 里 return h[r + 1] - h[l - 1 + 1] * p[r - l + 1];
    // for (int i = 1; i <= n; i ++ )
    //     h[i] = h[i - 1] * P + str[i - 1]; // 如果 原字符串 没有做处理的话, 这里是 str[i - 1]
    scanf("%s", str + 1); // 这里 str + 1, getHash 里 return h[r] - h[l - 1] * p[r - l + 1];
    for (int i = 1; i <= n; i ++ ) 
        h[i] = h[i - 1] * P + str[i]; // 加了scanf("%s", str+1) 或 str=' '+str的话,这里str[i]
    p[0] = 1; // p[i]存的是 P^i ，p的0次方是1
    for (int i = 1; i <= n; i ++ ) p[i] = p[i - 1] * P;
    while (m -- ) {
        int l1, r1, l2, r2;
        scanf("%d%d%d%d", &l1, &r1, &l2, &r2);
        if (getHash(l1, r1) == getHash(l2, r2)) puts("Yes");
        else puts("No");
    }
    return 0;
}