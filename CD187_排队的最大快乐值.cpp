//方法1：用邻接表存储树
#include <iostream>
#include <algorithm>
#include <cstring>
const int N = 5e5+10;
int h[N],e[N],ne[N],idx; //邻接表存储树
int happy[N]; //存储员工快乐值
int n;
int root;
void add(int a,int b){
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx;
    ++idx;
}
struct Info{
    int no;
    int yes;
    Info(int _no,int _yes):no(_no),yes(_yes){}
};
Info process(int root){
    int no  = 0 ;
    int yes = happy[root];
    for(int i = h[root];i!=-1; i = ne[i]){
        int j = e[i]; //j表示孩子节点的编号
        Info nextInfo = process(j); //求出孩子节点的Info
        no += max(nextInfo.yes,nextInfo.no); //root节点不来，那么它的孩子节点可以来也可以不来，加上二种方式的最大快乐值即可
        yes += nextInfo.no ; //root节点来，那么它的孩子节点就不能来，所以加上它孩子节点不来的最大快乐值即可
    }
    return Info(no,yes);
}
int main(){
    scanf("%d%d",&n,&root);
    memset(h,-1,sizeof h); //邻接表的表头初始化-1表示空
    for(int i = 1;i<=n;++i) scanf("%d",&happy[i]);
    for(int i = 1;i<=n-1;++i){
        int a,b;
        scanf("%d%d",&a,&b); //a是b的上级
        add(a,b); //a到b的一条边
    }
    Info allInfo = process(root); //返回根节点这棵树的Info
    printf("%d\n",max(allInfo.yes,allInfo.no));
    return 0;
}

//方法2：自定义多叉树结构(new操作耗时，推荐方法1，但要会写方法2的存储多叉树的结构定义）
#include <vector>
#include <iostream>
#include <cstdio>
using namespace  std;
//员工节点定义
struct TreeNode{
    int happy; //员工的快乐值
    vector<TreeNode*> next; //指向直属下属的指针构成的vector
    TreeNode(int h):happy(h){}
};
struct Info{
    int no;
    int yes;
    Info(int _no,int _yes):no(_no),yes(_yes){}
};
const int N = 5e5+10;
int n,root;
Info process(TreeNode* x){ //计算以x为根节点的子树的Info
    if(x == nullptr) return Info(0,0);
    int no = 0;
    int yes = x->happy;
    for(auto begin = x->next.begin();begin!=x->next.end();begin++){
        Info nextInfo = process(*begin);
        no += max(nextInfo.yes,nextInfo.no);
        yes += nextInfo.no  ;
    }
#if 0 //C++11遍历容器的循环方法
    for(TreeNode* inode : x->next){ //遍历x的所有孩子节点
        Info nextInfo = process(inode);
        no += max(nextInfo.yes,nextInfo.no);
        yes += nextInfo.no  ;
    }
#endif
    return Info(no,yes);
}
int main(){
    scanf("%d%d",&n,&root);
    vector<TreeNode* > happy(n+5); //存放包含所有员工TreeNode的vector
    int happyvalue ;
    for(int i = 1;i<=n;++i){
        scanf("%d",&happyvalue);
        happy[i] = new TreeNode(happyvalue);
    }
    int u,v;
    for(int i = 1;i<n;++i){
        scanf("%d%d",&u,&v);//u是v的上级
        happy[u]->next.push_back(happy[v]);
    }
    Info allInfo = process(happy[root]);
    printf("%d\n",max(allInfo.no,allInfo.yes));
    return  0;

}
