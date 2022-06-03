
#include <iostream>
using namespace std;
const int N = 1e5+10;
int n;
int stk[N],tt ; //tt=0表示栈空
int main(){
    ios::sync_with_stdio(false);
    cin>>n;
    //单调栈：栈中始终维护了单调 从小到大的顺序
    for(int i  = 0;i<n;++i){
        int x;
        cin>>x;
        while (tt && stk[tt] >=x) --tt; 
        //栈非空且栈顶元素大于等于x，那么栈顶元素不可能是答案，栈顶元素出栈，直到栈顶元素小于x或者栈空结束循环
        if(tt) cout<<stk[tt]<<" ";//栈非空，那么栈顶元素就是距离x左边最近比他小的数
        else cout<<-1<<" ";//栈空，没有答案，输出-1
        stk[++tt] = x;//当前数刚好大于栈顶元素，当前元素进栈，方便后面使用；
    }
    return  0;
	//建议大量读入输出还是使用printf和scanf，即便cin-cout加了ios::sync_with_stdio(false)也慢了很多
}