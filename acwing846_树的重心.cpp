#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 1e5+10; //数据范围是10的5次方
int h[N]; //邻接表存储树，有n个节点，所以需要n个队列头节点
const int M = N * 2; //以有向图的格式存放无向图，所以每个节点至多对应2n-2条边
int e[M]; //存储元素
int ne[M]; //存储列表的next值
int idx;  //单链表指针
bool st[N]; //保存点是否遍历过，访问过则标记为true
int ans = N; //ans是答案;
int n; //题目输入的n个节点
void add(int a,int b){ //加一个a指向b的边
    e[idx] = b;
    ne[idx] = h[a]; //头插
    h[a] = idx++;
}
int dfs(int u){ //dfs返回以u为根的子树中点的数量
    st[u] = true; //标记当前点已经被遍历过
    int sum = 1; //sum记录以u给根节点的子树大小，包括u，所以sum初值为1
    int res  = 0; //res记录 删除某个节点之后，最大的连通子图节点数
    for(int i = h[u]; i!=-1;i = ne[i]) { //遍历与当前节点u直接相连的节点
        int j = e[i]; //e数组中存放的才是节点编号;idx是指针用于串接链表
        if(!st[j]){ //如果没被访问过
             int s = dfs(j); //s记录当前子树大小
             res = max(res,s);
             sum+=s;
        }
    }
    res = max(res,n-sum); //n-sum 是当前节点删除后上面哪些节点构成的连通块数量
    ans = min(ans,res); //更新ans
    return sum; //dfs返回的是以u为根节点的子树中点的数量
}
int main(){
    cin>>n;
    memset(h,-1,sizeof  h ); //头节点都指向-1
    for(int i = 0;i<n-1;++i){
        int a,b;
        cin>>a>>b;
        add(a,b);
        add(b,a); //因为是无向图，所以需要加两条边
    }
    dfs(1); //从1开始遍历
    cout<<ans<<endl;
    return  0;
}