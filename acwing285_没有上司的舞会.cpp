//方法1：树形dp
#include <iostream>
#include <cstring>
#include <algorithm>
using  namespace  std;
const int N = 6010;
int n ;
int happy[N]; //存放每个员工的快乐值
int h[N],e[N],ne[N],idx ; //邻接表存储树
bool has_father[N]; //判断当前节点是否有父节点
int dp[N][2]; //dp表：
void dfs(int u){ //递归求每个状态
    dp[u][1] = happy[u]; //dp[u][1]表示u来，那么先加上u的快乐值(u来，那么u的儿子不能来了)
    for(int i = h[u];i!=-1; i = ne[i]){ //遍历u的所有孩子节点
        int j = e[i]; //j表示u的每个儿子的编号
        dfs(j);
        dp[u][0] += max(dp[j][0],dp[j][1]);
        //u不来，那么加上u的孩子节点来或者不来的最大值
        dp[u][1] += dp[j][0];
        //u来，那么只能加上u不来时候的快乐值
    }
}
void add(int a,int b){
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx;
    ++idx;
}
int main(){
    scanf("%d",&n);
    for(int i = 1;i<=n;++i) scanf("%d",&happy[i]); //读入每个员工的快乐值
    memset(h,-1,sizeof  h ); //邻接表的表头初始为-1
    //本题没有告诉我们根节点，需要自己先求出根节点
    for(int i = 0;i<n-1;++i){
        int a,b;
        scanf("%d%d",&a,&b); //b是a的父节点
        has_father[a]  = true;
        add(b,a); //插入一条b到a的边
    }
    int root = 1; //求根节点：从1开始枚举
    while (has_father[root]) root++; //循环结束后的root没有父节点，那就是根节点
    dfs(root);
    printf("%d\n",max(dp[root][0],dp[root][1])); //输出根节点来或者不来时候的快乐值
    return  0;
}
//方法2：比较好理解
#include <iostream>
#include <cstring>
#include <algorithm>
using  namespace  std;
const int N = 6010;
int n ;
int happy[N]; //存放每个员工的快乐值
int h[N],e[N],ne[N],idx ; //邻接表存储树
bool has_father[N]; //用来求出根节点的辅助数组
struct Info{
    int no; //头节点不来时候当前子树的最大快乐值和
    int yes; //头节点来的时候当前子树的最大快乐值和
    Info(int _no,int _yes):no(_no),yes(_yes){}
};
Info  process(int x){ //process返回以x为头节点的树的Info
    int no = 0;//x不来，那么快乐值初始是0
    int yes = happy[x]; //x来，那么快乐值初始是happy[x]
    for(int i = h[x];i!=-1;i = ne[i]) { //遍历x的所有孩子节点
        int j = e[i];//j表示u的每个孩子的节点编号
        Info  nextInfo  = process(j); //获得当前孩子的Info
        no += max(nextInfo.no,nextInfo.yes);
        //x不来，那么x的节点可以来也可以不来，所有加上它们二者的最大值
        yes += nextInfo.no;
        //x来，那么只能加上它的孩子节点不来时候的快乐值
    }
    return Info(no,yes);
}
void add(int a,int b){
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx;
    ++idx;
}
int main(){
    scanf("%d",&n);
    for(int i = 1;i<=n;++i) scanf("%d",&happy[i]); //读入每个员工的快乐值
    memset(h,-1,sizeof  h ); //邻接表的表头初始为-1
    //本题没有告诉我们根节点，需要自己先求出根节点
    for(int i = 0;i<n-1;++i){
        int a,b;
        scanf("%d%d",&a,&b); //b是a的父节点
        has_father[a]  = true;
        add(b,a); //插入一条b到a的边
    }
    int root = 1; //求根节点：从1开始枚举
    while (has_father[root]) root++; //循环结束后的root没有父节点，那就是根节点
    Info allInfo = process(root);
    int maxHappy = max(allInfo.no,allInfo.yes);
    printf("%d\n",maxHappy);
    return  0;
}
