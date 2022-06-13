#include <iostream>
#include <cstring>
using namespace  std;
const int N = 1e6+10;
int n,m;
int h[N],e[N],ne[N],idx; //邻接表存储图
int q[N];  // 队列保存入度为0的点，也就是能够输出的点
int d[N];   //保存每个点的入度
void add(int a,int b){//插入这条边
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx;
    idx++;
}
bool topsort(){
    int hh = 0,tt= -1;
    for(int i = 1;i<=n;++i){
        if(!d[i]){
            q[++tt]  = i;  //把所有入度为0的节点添加到队列中去
        }
    }
    while (hh<=tt){ //队列非空
        int t = q[hh++] ; //取出队头元素
        for(int i = h[t];i!=-1;i = ne[i]){
            int j = e[i];
            d[j] -- ; //入度--
            if(d[j] == 0)   q [++tt] = j; //入度如果为0加到队列里
        }
    }
    return tt  == n-1; //队列进了n个点,那就是有向无环图，存在拓扑序，就在队列里面
}
int main(){
    cin>>n>>m;
    memset(h,-1,sizeof  h);
    for(int i = 0;i<m;++i){
        int a,b;
        cin>>a>>b;
        add(a,b);
        d[b] ++; //插入一条边的时候记得更新入度
    }
    if(topsort()){ //存在拓扑排序就输出，不存在输出-1
        for(int i = 0;i<n;++i){
            printf("%d ",q[i]);
        }
    }else puts("-1");
    return  0;
}