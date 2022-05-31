#include <iostream>
 #include <string>
 #include <vector>
 using namespace std;
 //C=A-B
 vector<int> sub(vector<int> &A,vector<int>&B){ //输入保证了A>B
    vector<int> C;
    for(int i  = 0,t = 0;i<A.size();++i){ //开始借位t是0
        t = A[i]-t;
        if(i<B.size()){ //每次需要判断B[i]是否存在，因为B的位数可能小于A 
            t -=B[i]; //只有B[i]存在才减去它 
        }
        //t>=0就是t本身，t小于0就要加上10 ; 用(t+10)%10可以综合这二种情况
        C.push_back((t+10)%10); 
        if(t<0){
            t= 1; //t<0说明需要借位
        }else {
            t = 0;
        }
    }
    //如果是123-120结果是003,我们需要去掉0
    //vector中0位存放个位，1位存放十位....
    while(C.size()>1 && C.back()==0) C.pop_back(); 
    //C.size()>1保证结果如果是0000还会留下一个0
    return C;
 }
 //判断是否有:A>=B
 bool cmp(vector<int>& A,vector<int> &B){
    if(A.size()!=B.size()) return A.size()>B.size();  
    //如果位数不同，谁位数大谁就大
    for(int i = A.size()-1;i>=0;--i){ //位数相同，从高位开始比较
        if(A[i]!=B[i]){
            return A[i]>B[i];
        }
    }
    return true;  //位数相同且每个位都相同，返回相等
 }
 int main(){
    string a,b;
    vector<int> A,B; //本题不考虑负数情况，假设A和B都是正数
    cin>>a>>b;
    for(int i = a.size()-1;i>=0;--i){
        A.push_back(a[i]-'0');
    }
    for(int i  = b.size()-1;i>=0;--i){
        B.push_back(b[i]-'0');
    }
    if(cmp(A,B)){ //A>B
        auto C = sub(A,B);
        for(int i  = C.size()-1;i>=0;--i){
            printf("%d",C[i]);
        }
    }else {
        auto C = sub(B,A);
        printf("-");
        for(int i  = C.size()-1;i>=0;--i){
            printf("%d",C[i]);
        }
    }
     return 0;
 }