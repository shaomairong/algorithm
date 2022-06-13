#include <iostream>
#include <cstring>
using  namespace std;
const int N  = 1e6+10;
int h[N],e[N],ne[N],idx;//邻接表
int d[N],q[N]; //d是距离，q是队列
int n,m;
void add(int a,int b){
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx;
    idx++;
}
int bfs(){
    int hh = 0,tt = 0; //队列头尾
    q[0]  = 1;//第一个元素是起点进队列
    memset(d,-1,sizeof  d); //距离数组初始化-1表示没有被遍历过
    d[1] = 0;  //第一个点距离是1
    while (hh<=tt){ //队列非空
        int t= q[hh++]; //取得队头
        for(int i = h[t];i!=-1;i = ne[i]){
            int j = e[i]; //e数组中存放的是图中点的编号
            if(d[j] == -1){
                d[j]   = d[t] +1;
                q[++tt] = j;
            }
        }

    }
    return d[n];
}
int main(){
    cin>>n>>m;
    memset(h,-1,sizeof  h);
    for(int i = 0;i<m;++i){
        int a,b;
        cin>>a>>b;
        add(a,b );
    }
    cout<<bfs()<<endl;
    return  0;
}