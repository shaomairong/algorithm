#include <iostream>
using namespace  std;
const int N = 20; //N是10，对角线开二倍为20
int n;
char g[N][N]; //方案:用字符串记录
bool col[N],dg[N],udg[N];
//col[N]同一列只能有一个，正对角线和反对角线
void dfs(int u){
    if(u == n){ //找到方案了，输出
        for(int i = 0;i<n;++i) puts(g[i]);
        puts("");
        return;
    }
    //当前枚举是第u行，皇后应该放到那一列
    for(int i = 0; i<n;++i){ //从第一列开始枚举
        if(! col[i] && !dg[u+i] && !udg[n-u+i]     ) { 
            // 当前列没有放过 && 对角线没有放过  && 反对角线没有放过
            g[u][i] = 'Q';
            col[i] = dg[u+i] =udg[n-u+i] = true;
            dfs(u+1);
            col[i] = dg[u+i] =udg[n-u+i] = false; //恢复现场
            g[u][i] = '.'; //恢复现场
        }
    }
}
int main(){
    cin>>n;
    for(int i = 0;i<n;++i){
        for(int j = 0;j<n;++j){
            g[i][j] = '.';
        }
    }
    dfs(0)  ;
    return 0;
}