#include <iostream>
using namespace std;
const int N = 1e5+10;
int a[N],b[N];
int main(){
    ios::sync_with_stdio(false);
    int n,m,x;
    cin>>n>>m>>x;
    for(int i  =0;i<n;++i){
        cin>>a[i];
    }
    for(int i = 0;i<m;++i){
        cin>>b[i];
    }
    //双指针：一般是写出暴力，然后看有无单调性，进行优化为双指针
    //i从前往后，j从后往前 
    int j = m-1;
    for(int i = 0;i<n;++i){
        while (j>=0 && a[i] + b[j] >x ) --j;
        if(j>=0 && a[i]+b[j]== x)  {
            cout<<i<<" "<<j<<endl;
            break;
        }
    }
    return  0;
}
