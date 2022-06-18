#include <iostream>
using  namespace  std;
int n;
const int N = 1e3+10;
int a[N];
int dp[N];
int main(){
    cin>>n;
    for(int i = 1;i<=n;++i){
        cin>>a[i];
    }
    dp[1] = 1;//base case :以第一个数结尾的最长上升子序列长度就是1
    for(int i = 2;i<=n;++i){ //从第二个数开始遍历
        dp[i] = 1; //假设i前面没有比他小的数，那么以i结尾的最长上升子序列长度就是1,先给默认值
        for(int j = 1;j<i;++j ){
            //状态转移方程: dp[i]=max(dp[i],dp[j]+1), i<j且a[i]>a[j]
            if(a[j]<a[i]){
                dp[i] = max(dp[i],dp[j]+1);
            }
        }
    }
    int max = -1;
    for(int i = 1;i<=n;++i){
        if(dp[i]>max) max = dp[i]   ;
    }
    cout<<max<<endl;
    return  0;

}
//---------------改版-求最长上升子序列的长度，并且把它打印出来
#include <iostream>
#include <stack>

using  namespace  std;
const int N = 1e3+10;
int arr[N];
int dp[N];
int g[N ];
int n;
int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i =1;i<=n;++i){
        cin>>arr[i];
    }
    for(int i  = 1;i<=n;++i){ //从前往后计算每一个状态
        dp[i] = 1; //只有a[i]一个数
        g[i] = 0; //表示只有一个数
        for(int j = 1;j<i;++j){
            //状态转移方程: dp[i] = max{dp[j]+1} , i<j 且 arr[i]>arr[j]
            if(arr[i] > arr[j] ){
                if(dp[i] < dp[j] + 1){
                    dp[i] = dp[j] + 1;
                    g[i] = j;
                }
            }
        }
    }
    int k = 1;
    for(int i = 2;i<=n;++i){
        if(dp[k] < dp[i]){
            k = i;
        }
    }
    cout<<dp[k]<<endl;
    stack<int> stack;
    for(int i  = 0,len = dp[k];i<len;++i){
        stack.push(arr[k]);
        k = g[k];
    }
    while (!stack.empty()){
        cout<<stack.top()<<" ";
        stack.pop();
    }
    return  0;
}