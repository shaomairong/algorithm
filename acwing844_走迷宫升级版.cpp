#include<stdio.h>
#include<queue>
#include<iostream>
using namespace std;
char maze[201][201];
int sx, sy, tx, ty;
//左右上下4个方向
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int m, n;
struct node {
    int x,  y, dis;
};
bool operator < (const node & a, const node & b) {
    return a.dis > b.dis;  //为优先级队列选取最小距离
}
void bfs() {
    priority_queue<node> que;
    node st { sx,sy,0 };
    maze[sx][sy] = '#';
    que.push(st);
    while (!que.empty()) {
        node p = que.top();
        que.pop();
        //若已找到，则退出
        if (p.x == tx && p.y == ty) {
            cout << p.dis << endl;
            return;
        }
        for (int i = 0; i < 4; ++i) {
            int nx = p.x + dx[i];
            int ny = p.y + dy[i];
            node np{ nx,ny, 0};
            if (nx >= 0 && nx < n&&ny >= 0 && ny < m && maze[nx][ny] != '#') {
                if (maze[nx][ny] == 'X')
                    np.dis = p.dis + 2;
                else
                    np.dis = p.dis + 1;
                maze[np.x][np.y] = '#';
                que.push(np);

            }
        }
    }
    printf("impossible\n");
}
int main() {
    while (cin>>n>>m) {
        for (int i = 0; i < n; i++)
            scanf("%s", maze[i]); //一次读入一行
        for(int i=0; i<n; i++)
            for (int j = 0; j < m; j++) {
                if (maze[i][j] == 'S')
                    sx = i, sy = j;
                else if (maze[i][j] == 'T')
                    tx = i, ty = j;
            }
        bfs();
    }
    return 0;
}