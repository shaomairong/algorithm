#include <iostream>
using namespace  std;
const int N = 1e3+10;
int a[N][N],b[N][N]; //初始都是0，0数组和0数组肯定互为前缀和数组和差分数组
void insert(int x1,int y1,int x2,int y2,int c ){
    b[x1][y1]    +=c;
    b[x1][y2+1] -=c;
    b[x2+1][y1] -=c;
    b[x2+1][y2+1]+=c;
}
int main(){
    ios::sync_with_stdio(false);
    int n,m,q;
    cin>>n>>m>>q;
    for(int i = 1;i<=n;++i)
        for(int j = 1;j<=m;++j)
            cin>>a[i][j];
    for(int i =1;i<=n;++i)
        for(int j = 1;j<=m;++j)
            insert(i,j,i,j,a[i][j]);
            //构造b为差分数组
    while (q--){
        int x1,y1,x2,y2,c;
        cin>>x1>>y1>>x2>>y2>>c;
        insert(x1,y1,x2,y2,c); //对差分数组操作
    }

    for(int i =1;i<=n;++i){
        for(int j =1;j<=m;++j){
            b[i][j]  = b[i][j] + b[i-1][j] +b[i][j-1] -b[i-1][j-1];
 //由b这个二维差分数组还原为二维前缀和数组新的b 
 //二维差分数组还是数组，即通过这里是通过二维数组构造前缀和数组的公式
            cout<<b[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}