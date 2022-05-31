#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
//A/b 商是C，余数是r
vector<int> div(vector<int> & A,int b,int &r){ //余数r是通过引用传递回去
    vector<int> C; //01:11:06
    r = 0; //初始余数r是0
    for(int i =  A.size()-1;i>=0;--i){ //除法是从最高位开始计算
        r = r*10+A[i];
        C.push_back(r/b); //商
        r = r%b;
    }
    reverse(C.begin(),C.end());
    while (C.size()>1  && C.back() == 0) C.pop_back();
    return C;
}
int main(){
    string  a ;
    int b;
    cin>>a>>b;
    vector<int> A;
    for(int i = a.size()-1;i>=0;--i){
        A.push_back(a[i]-'0');
    }
    int r ; //保存余数
    auto C = div(A,b,r);
    for(int i = C.size()-1;i>=0;--i){
        printf("%d",C[i]);
    }
    cout<<endl;
    cout<<r<<endl;
    return 0;
}