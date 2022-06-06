#include <iostream>
#include <algorithm>
using std::swap;
const int N = 1e6+10;
int n,m;
int h[N],size;
void down(int u){
    int t = u; //用t存放三者最小的下标
    if(2 * u <=size && h[u*2] < h[t]) t = u*2; //左儿子存在且左儿子的值小于h[t]
    if(2 * u +1 <= size && h[u*2+1] < h[t]) t = u*2 +1;//右儿子存在且右儿子的值小于h[t]
    //现在t存的就是三个点中最小值的编号
    if(t!=u){//根节点不是最小值，就需要交换
        swap(h[u],h[t]);
        down(t);
    }
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i = 1;i<=n;++i){ 
        scanf("%d",&h[i]);
    }
    size = n;
    for(int i = n/2;i;--i){ //O(N)建小顶堆，此时最小元素在h[1]位置
        down(i);
    }
    while (m--){
        printf("%d ",h[1]);
        h[1] = h[size--]; //把数组末尾元素赋值到开头位置,相当于删除了堆顶元素，然后down(1)
        down(1);
    }
    return  0;
}