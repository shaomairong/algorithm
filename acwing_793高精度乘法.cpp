#include <iostream>
#include <vector>
#include <string>
using namespace std;
//C = A * b  
vector<int> mul(vector<int>& A,int b){
    vector<int> C;
    int t = 0; //最开始进位是0
    for(int i = 0;i<A.size() || t ;++i){ //||t保证最后如果有进位也加上去
        if(i<A.size())  t = A[i] * b + t; //当A[i]没有遍历完就要加上
        C.push_back(t%10);
        t = t/10; //进位
    }
    while(C.size()>1 && C.back()==0 ) C.pop_back(); //去除前导0 
    return C;
}

int main(){
    string a; //a很长用字符串读入
    int b; //b一个整数
    cin>>a>>b;
    vector<int> A ; //string的大整数存放在vector中
    for(int i = a.size()-1;i>=0;--i){
        A.push_back(a[i]-'0');
    } 
    auto C = mul(A,b);
    for(int i =C.size()-1;i>=0;--i){
        printf("%d",C[i]);
    }
    return 0;
}