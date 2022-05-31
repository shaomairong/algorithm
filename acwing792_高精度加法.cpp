#include <iostream>
#include <vector>  //用vector存储大整数
#include <string>
using namespace std;
const int N = 1e6+10; //通过是多开1的空间，但是这里为了保险我们多开10个
vector<int> add(vector<int> &A,vector<int> &B){ //vector使用引用传参
    vector<int> C;
    int t = 0; //初始进位是0
    for(int i = 0;i<A.size() || i<B.size();++i){ //只要A或者B没有完，就一直去做
        if(i<A.size()) t+=A[i];
        if(i<B.size()) t+=B[i]; //如果二个数组中右i位置，那么加上那个位置的值
        C.push_back(t%10);
        t = t/10; //进位存储
    }
    if(t){//容易忽略的一步，如果最后最高位还有进位
        C.push_back(t); 
    }
    return C;
}
int main(){
    //因为大整数很长，所以用字符串读进来
    string a,b; //a = "123456"
    vector<int> A,B;
    cin>>a>>b;
    for(int i = a.size()-1;i>=0;--i){//A = [6,5,4,3,2,1] 到这存放：数组第0位表示个位，第1位表示十位
        A.push_back(a[i]-'0'); //字符-'0'得到对应的整数，然后存放到vector中
    }
    for(int i = b.size()-1;i>=0;--i){
        B.push_back(b[i]-'0');
    }
    auto C = add(A,B);
    for(int i = C.size()-1;i>=0;--i){
        printf("%d",C[i]);
    }
    return 0;
}