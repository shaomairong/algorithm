#include <iostream>
using namespace std;
const int N = 1e6+10;
int a[N],q[N],n,k;

int main(){
    scanf("%d%d",&n,&k);
    for(int i = 0;i<n;++i) scanf("%d",&a[i]);
    int hh = 0,tt  = -1; //初始化队列q,hh表示队头，tt表示队尾
    for(int i = 0;i<n;++i){
        //队列里面存放得是数组元素的下标
        //判断队头是否已经滑出窗口 （当前终点是i，起点就是i-k+1)
        if(hh<=tt && i-k+1 > q[hh] ) ++hh; //清除过期下标
            //队列非空 且 q[h]出了窗口，那就hh++
            //因为每次窗口移动一位，所以每一次队列里面最多只有一个数不在窗口内，所以if足够
        while (hh<=tt && a[q[tt]] >=a[i]     ) --tt;//如果队尾的数大于等于当前数，那么队尾元素弹出
        q[++tt] = i; //将当前元素的下标添加到队列末尾
        if(i>=k-1) printf("%d ",a[q[hh]]); //只有当形成窗口大小了，才输出窗口中的最小值
    }
    printf("\n");
    hh = 0,tt = -1;
    for(int i = 0;i<n;++i){
        if(hh<=tt && i-k+1 >q[hh]) ++hh;
        while (hh<=tt && a[q[tt]] <=a[i]) --tt;
        q[++tt] = i;
        if(i>=k-1) printf("%d ",a[q[hh]]);
    }
    printf("\n");
    return  0;
}