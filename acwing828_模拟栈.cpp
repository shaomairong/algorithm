#include <iostream>
using namespace std;


const int N = 1e6+10;
int stk[N],tt ; //用tt表示栈顶，tt=0表示栈空，所以数据是从1开始存放；所以添加时stk[++tt]= x; 

int main(){
    int m;
    cin>>m;
    while (m--){
        string c ;
        cin>>c;
        if(c == "push"){
            int x;
            cin>>x;
            stk[++tt] = x;
        }else if(c == "pop"){
            --tt;
        }else if(c == "empty"){
            if(tt>0){ 
                cout<<"NO"<<endl;
            }else {//tt为0时表示栈空
                cout<<"YES"<<endl;
            }
        }else { //c="query"
            cout<<stk[tt]<<endl;
        }
    }
    return  0;
}
