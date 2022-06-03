 #include <iostream>
using namespace std;

const int N = 1e5+10;
int m;
int e[N],l[N],r[N],idx;
void init(){//初始化
    //0表示左端点，1表示右端点,作为二端边界
    r[0] = 1 ,l[1] =0; //0表示head，1表示tail
    idx = 2; //0,1已经被占用了，所以插入的下标从2开始
}
void add(int k,int x){//在第k个点的右边插入x:add(k,x)
    //如果想在k的左边插入x可以调用:add(l[k],x)
    e[idx ] = x;
    r[idx] = r[k];
    l[idx] = k;
    l[r[k]] = idx;
    r[k] =  idx;
    ++idx;
}
void remove(int k){//删除第k个点
    r[l[k]] = r[k];
    l[r[k]] = l[k];
}
int main(){
    ios::sync_with_stdio(false);
    int m;
    cin>>m;
    init();
    while (m--){
        string op;
        cin>>op;
        int k,x;
        if( op == "L"){
            cin>>x;
            add(0,x);
        }else if(op == "R"){
            cin>>x;
            add(l[1],x);
        }else if(op =="D"){
            //下标是从2开始的;所以将第k个插入的数删除即删除k+1位置的数
            cin>>k;
            remove(k+1);
        }else if(op =="IL"){
            cin>>k>>x;
            //下标从2开始;第k个插入的数即k+1位置，它左边是l[k+1],即在l[k+1]后面插入
            add(l[k+1],x);
        }else if(op == "IR") { 
            cin>>k>>x;
            //下标从2开始;第k个插入的数即k+1位置
            add(k+1,x);
        }
    }
    //遍历输出结果:0表示头，r[0]就表示第一个数的节点 ; 1表示结尾节点
    for(int i = r[0];i!=1;i = r[i]){
        cout<<e[i]<<" ";
    }
    cout<<endl;
    return  0;
}
