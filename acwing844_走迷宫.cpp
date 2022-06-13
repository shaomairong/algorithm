#include <iostream>
#include <queue>
#include <utility>
#include <stack>
#include <cstring>
using  namespace  std;
const int N = 110;
int g[N][N]; //用邻接矩阵存储图
int d[N][N]; //存放起点到该点的距离
using PII  = pair<int,int>;
PII pre[N][N]; //存放到该点的是哪一个点
int n,m;
int  bfs(){
    queue<PII> q;
    q.push({1,1}); //[1,1]起点入队
    g[1][1] = 1; //设置该点已经被访问过了
    memset(d,-1,sizeof d);
    d[1][1] = 0; //从起点到该点的距离是1
    int dx[] = {0,0,-1,1};
    int dy[]={-1,1,0,0}; //四个方向向量
    while (!q.empty()){
        PII p = q.front(); //取出队头元素，尝试四个方向能否走
        q.pop();
        for(int i = 0;i<4;++i){
            int x = p.first + dx[i],y = p.second + dy[i];
            if(x >=1 &&  x<=n && y >=1 && y<=m && g[x][y] == 0 && d[x][y] == -1){
                //(x,y)不能越界 且 g[x][y]==0表示可以走 且 只更新未被访问的点到源点的距离 (要求d[x][y] == -1)
                d[x][y] = d[p.first][p.second] +1; //更新到这个点的距离
                g[x][y] = 1; //设置这个点被访问过了
                pre[x][y] = p; //记录到是从那个点到达这个点的
                q.push({x,y}); //当前点入队列，方便后续遍历
            }
        }
    }
    int x = n,y = m;
    stack<PII>  stack;
    stack.push({x,y});
    while (x>1 || y>1){
        PII t = pre[x][y];
        stack.push(t);
        x = t.first,y = t.second;
    }
    while (!stack.empty()){
        PII t = stack.top();
        stack.pop();
        // cout<<"["<<t.first<<","<<t.second<<"]"<<endl;
    }
    return d[n][m];
}
int main(){
    ios::sync_with_stdio(false),cin.tie(0), cout.tie(0);
    cin>>n>>m;
    for(int i =1;i<=n;++i){
        for(int j= 1;j<=m;++j){
            cin>>g[i][j];
        }
    }
    cout<<bfs()<<endl;
    return 0;
}