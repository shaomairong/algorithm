#include <iostream>
using namespace std;

const int N = 100010;
int a[N], b[N];
// b为差分数组，a是b的前缀和数组// b[r] + b[r - 1] + ...... + b[l] = a[r] - a[l - 1]
// 要给a数组中[l, r]之间的每个数加上c，即为b[l] += c，b[r + 1] -= c
int main()
{
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
        // 赋值的同时，可以求差分数组b
        b[i] = a[i] - a[i - 1];
    }
    while(m--) {
        int l, r, c;
        cin >> l >> r >> c;
        b[l] += c, b[r + 1] -= c;
    }
    // 对b求前缀和，就得到了处理过后的a数组
    for(int i = 1; i <= n; ++i)
        a[i] = b[i] + a[i - 1]; 
    for(int i = 1; i <= n; ++i)
        cout << a[i] << ' ';
    return 0;
}
//----------------------------------------------------
 #include<iostream>
using namespace std;
const int N = 1e6+5;
int a[N], b[N];
void insert(int l , int r , int x){
    b[l] += x;
    b[r + 1] -= x;
}
int main(){
    int n , m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin>>a[i];
    for(int i = 1; i <= n; i++)
        insert(i,i,a[i]); //这一步是改变b，使得b仍然是a的差分数组
    while(m--){
    //这一步是主要操作，通过操作差分数组b，间接使得把a数组【l,r】里面的数全部加上c
        int l, r,c;
        cin>>l>>r>>c;
        insert(l,r,c);
    }    
    //差分数组b的前i项和就是a【i】
    for(int i = 1; i <= n; i++) b[i] = b[i - 1] + b[i];
     //把b数组前i项求和，这时候b【i】就变成了a【i】
    for(int i = 1; i <= n; i++) a[i] = b[i]; //把b【i】赋给a【i】
    for(int i = 1; i<=n; i++)cout<<a[i]<<" ";
    return 0;
}