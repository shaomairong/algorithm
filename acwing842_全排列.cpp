#include <iostream>
using  namespace  std;
const int N = 10; //数据范围<=7
int n;
int path[N]; //保存路径:从0开始到n-1
bool st[N]; //记录位置是否被用过:1~n的数
void dfs(int u){
    if(u == n){ //从第0个位置开始，到第n个位置就结束了，输出结果
        for(int i = 0;i<n;++i){
            printf("%d ",path[i]);
        }
        puts("");
        return;
    }
    for(int i = 1;i<=n;++i){ //空位上可以选择的数据是1~n
        if(!st[i]){ //当前这个数i没有被用过
            path[u] = i; //放入空位
            st[i] = true;//数字被用，修改状态
            dfs(u+1); //填下一个位
//            path[u] = 0; 因为path[u]会被覆盖，所以这一句可以不加
            st[i] = false; //恢复现场
        }
    }
}
int main(){
    cin>>n;
    dfs(0); //从第0个位置开始看
    return  0;
}