#include <iostream>
using namespace  std;
int lowbit(int x){
    return  x & -x;// -x = ~x +1 ;
    //求x最后一位1
}
int main(){
    ios::sync_with_stdio(false);
    int n ;
    cin>>n;
    while (n--){
        int x;
        cin>>x;
        int res = 0;
        while (x) {
            x -= lowbit(x);
            //每次减去x的最后一位1，减了多少次说明x有多少位1
            ++res;
        }
        cout<<res<<endl;
    }
    return 0;
}
