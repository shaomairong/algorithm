#include <iostream>
using  namespace  std;
const int N  = 1e6+10;
int n,m;
int p[N],setSize[N];
//size[]只有祖宗节点的有意义，表示祖宗节点所在集合中的点的数量
int find(int x){//返回x的祖宗节点+路径压缩
    if(x!=p[x]) p[x] = find(p[x]);
    return p[x];
}
void merge(int a,int b){
    if(find(a) == find(b)) return ;
    setSize[find(b)] += setSize[find(a)];//先更新集合节点数量，在进行下面的连接
    p[find(a)] = find(b); //让a的祖宗节点的父亲是b节点的祖宗节点
}
void init(int n){
    for(int i =1;i<=n;++i){ //从1开始存放
        p[i] = i;//初始化每个节点都是单独集合，那么它的父节点是它自己
        setSize[i] = 1;//集合中节点数量是1
    }
}
bool isSameSet(int a,int b){
    return find(a) == find(b);
}
int getSetSize(int a){
    return setSize[find(a)] ;
}
int main(){
    scanf("%d%d",&n,&m);
    init(n);
    while (m--){
        char op[5];
        int a,b;
        scanf("%s",op);
        if(op[0] == 'C'  ){
            scanf("%d%d",&a,&b);
            merge(a,b);
        }else if(op[1] == '1'){
            scanf("%d%d",&a,&b);
            if(isSameSet(a,b)) puts("Yes");
            else puts("No");
        }else {
            scanf("%d",&a);
            printf("%d\n", getSetSize(a));
        }
    }
    return  0;
}
