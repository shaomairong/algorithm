#include <iostream>
#include <cstring>
using  namespace  std;
const int N = 310;
int n,m;
int h[N][N];
int dp[N][N];
//枚举上下左右的技巧:偏移量
int dx[4]={-1,1,0,0},dy[4]={0,0,-1,1};
int process(int x,int y){
    int & v = dp[x][y];
    if(v!=-1) return v;
    v = 0;
    for(int i = 0;i<4;++i){ //看当前位置的四个方向是否能走
        int a = x + dx[i] , b = y + dy[i];
        if(a>=1 && a<=n && b>=1 && b<=m && h[a][b] < h[x][y]){//方向没有越界 且 那个位置的值小于当前位置值
            v = max(v, process(a,b)); //找出四个方向上能取得最大值
        }
    }
    return v=v+1; //最后要加上当前位置这一步
}
int main(){
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i ++ )
        for (int j = 1; j <= m; j ++ )
            scanf("%d", &h[i][j]);
    memset(dp, -1, sizeof dp);
    int res = 0;
    for (int i = 1; i <= n; i ++ )
        for (int j = 1; j <= m; j ++ )
        //找出从每个位置出发能滑行得最大值
            res = max(res, process(i, j));
    printf("%d\n", res);
    return  0;
}