#include <iostream>
using  namespace  std;
const int N = 1e6+10;
int p[N]; //father数组，存放每个元素的父节点是谁
int n,m;
int find(int x){ //返回x所在集合的编号(即返回x的祖宗节点，祖宗节点代表集合编号) +路径压缩优化
    if(p[x] !=x) p[x] = find(p[x]);
    return p[x];
}
void merge(int a,int b){//将a和b节点所在的集合合并成一个集合
    p[find(a)] = find(b); //a的祖宗节点的父亲等于b的祖宗节点,即合并二个点所在的集合
}
bool sameSet(int a,int b){//判断二个节点是不是在同一个集合
    return find(a) == find(b);
}

int main(){
    scanf("%d%d",&n,&m);
    for(int i = 1;i<=n;++i){
        p[i] = i;  //初始时每个节点都是单独的集合，那么它们的父亲就是自己
    }
    while (m--){
        char op[2];
        //scanf读入一个字符也用%s技巧;因为有可能出题人加空格，所以不管读字母还是读字符串，都用%s来读取
        int a,b;
        scanf("%s%d%d",op,&a,&b);
        if(op[0] == 'M' ){
            merge(a,b);
        }else {
            if(sameSet(a,b)){
                puts("Yes");
            }else {
                puts("No");
            }
        }
    }
    return 0;
}
