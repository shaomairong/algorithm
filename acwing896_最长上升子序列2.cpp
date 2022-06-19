#include <iostream>
#include <vector>
using  namespace  std;
const int N = 1e5+10;
int n;
int a[N];
int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i = 1;i<=n;++i){
        cin>>a[i];
    }
    vector<int> stk; //用vector模拟队列
    stk.push_back(a[1]) ;
    for(int i = 1;i<=n;++i){
        if(a[i] > stk.back()){ //如果该元素大于栈顶元素，将该元素进栈
            stk.push_back(a[i]);
        }else {
            *lower_bound(stk.begin(),stk.end(),a[i]) = a[i];
            //替换掉第一个大于等于这个数字的那个数
        }
    }
    cout<<stk.size()<<endl;
    return  0;
}