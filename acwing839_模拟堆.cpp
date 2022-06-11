#include <iostream>
#include <algorithm>
#include <string.h>
using std::swap;
const int N = 1e6+10;
int n,m;
int h[N],size;
int ph[N],hp[N];
//【pointer heap】
//ph[k]表示第k个插入的点在数组中的下标
//hp[k]表示下标为k的数是第几个插入的
void heap_swap(int a,int b){
    //hp[a]表示a是第几个插入的，hp[b]表示b是第几个插入的
    //ph[k]表示第k个插入的数对应元素的位置
    swap(ph[hp[a]],ph[hp[b]]);
    swap(hp[a],hp[b]);
    swap(h[a],h[b]);
}
void down(int u){ //向下调整
    int t = u;
    if(2 * u <=size  && h[2 * u] < h[t]) t = 2*u;
    if(2 * u +1 <=size && h[2 * u +1] < h[t] ) t= 2*u+1;
    if(t!=u){
        heap_swap(t,u);
        down(t);
    }
}
void up(int u){ //向上调整
    while (u/2 && h[u/2] > h[u]){
        heap_swap(u/2,u);
        u = u/2;
    }
}
int main(){
    int n,m=0;//m记录当前是第几个插入的数
    int k,x;
    scanf("%d",&n);
    while (n--){
        char op[10];
        scanf("%s",op);
        //strcmp(a,b) 如果a和b相等返回0
        if(!strcmp(op,"I")){
            scanf("%d",&x);
            ++m;
            ++size;
            ph[m] = size;//第m个插入的数在size位置
            hp[size] = m;//堆里面size位置的数是第m次插入的
            h[size] = x;
            up(size);
        }else if(!strcmp(op,"PM"))  printf("%d\n",h[1]); //输出集合中最小值
        else if(!strcmp(op,"DM")){ //删除最小值
            heap_swap(1,size); //将数组最后位置的数交换到开头存储位置，其中包含了hp与ph的交换
            --size;
            down(1) ;
        }else if(!strcmp(op,"D")) { //删除第k个插入的数
            scanf("%d",&k);
            k  = ph[k]; //通过ph找到第k个数在堆中的位置
            heap_swap(k,size);//将堆尾元素和k位置元素交换
            --size;
            down(k);
            up(k); //down和up只会执行一个
        }else { //将第k个插入的数修改
            scanf("%d%d",&k,&x);
            k = ph[k]; //通过ph获得第k个插入的数的下标
            h[k]= x; //修改k位置元素的值
            down(k);
            up(k); //down和up只会执行一个
        }
    }
    return  0;
}