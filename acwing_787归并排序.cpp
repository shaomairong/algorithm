#include <iostream>
#include <algorithm> //swap


using namespace std;

const int N = 1e6+10;
int tmp[N];
    void merge(int *arr,int L,int M,int R){
        int N = R-L+1;
        // int * tmp = new int [N]; //辅助数组,这里每次merge都要开辟数组，其实可以在外部开辟全局tmp数组一次就行了
        int i = 0;
        int p1 = L;//左边开头
        int p2 = M+1;//右边开头
        while (p1<=M && p2<=R){
            tmp[i++] =  arr[p1]<=arr[p2] ? arr[p1++]:arr[p2++];
            //注意比较：arr[p1]<=arr[p2]写成<=才能是稳定排序
        }//while退出了，说明p1或者p2有一个越界了，所以下面二个while只会执行一个
        while (p1<=M){
            tmp[i++] = arr[p1++];
        }
        while (p2<=R){
            tmp[i++] = arr[p2++];
        }
        //最后从tmp数组拷贝元素到arr中，注意arr开始下标是从L开始，tmp下标是从0开始
        for(i = 0;i<N;++i){
            arr[L+i] = tmp[i]; //通过L+i定位
        }
        // delete tmp;
    }
    void mergeProcess(int *arr,int L,int R){
        if(L>=R){ //base case:一个元素有序，直接返回
            return;
        }
//        int mid = L+(R-L)/2;
        int M= L +((R-L)>>1);
        mergeProcess(arr,L,M); //递归调用mergeProcess对左边排好序
        mergeProcess(arr,M+1,R); //递归调用mergeProcess对右边排好序
        merge(arr,L,M,R); //二个有序子数组进行merge，那么数组整体就有序了
    }
    void mergeSort1(int *arr,int N){ //递归版本归并排序
        if(arr == nullptr || N <2){
            return;
        }
        mergeProcess(arr,0,N-1);
    }
    void mergesort2(int *arr,int N){ //非递归版本归并排序
        if(arr == nullptr || N<2){
            return;
        }
        int step = 1; //步长从1开始，然后2倍递增
        while (step<N){//步长要小于数组长度，当步长等于数组长度时候就结束
            int L = 0; //左组的第一个位置(步长不同，但是第一个左组都是从0开始)
            while (L<N){ //L来到每个左组的第一个，所以L要小于N
                int M = L+step-1; //M是左组的最后一个元素下标
                if(M>=N){ //M如果越界了，说明左组凑不够step个，那么当前步长的排序结束，后面进行步长更新
                    break;
                }//if出来说明M没有越界,但如果M是N-1位置了，那么只有左组没有右组，也跳过当前步长
                if(M==N-1){
                    break;
                }//if出来表示：左组凑够了step个，那么右组第一个元素下表是M+1
                //右组能凑够step个时候，右组最后一个元素下标应该是:M+1+step-1 = M+step
                //右组凑不够step个时候，右组最后一个元素下标应该是N-1结束位置
                //比如当前步长是4：  左组 1 4 6 8 右组 3 9 ，那么右组凑不够4个元素了，右组最后一个元素下标是N-1
                int R = std::min(N-1,M+step);
                merge(arr,L,M,R);//左组L~M，右组M+1~R,且已经判断没有越界了，可以开始merge了
                L= R+1; //下一个左组开始的L，上面while会对L进行越界判断:while(L<N)
            }
            /*下面这个if是防止溢出的关键代码:
          我们都知道整数是由最大值的，大概二十多亿。
          假设数组长度N非常靠近整数最大值，而步长是从1 2 4 8 16 ....setp
          有可能步长最后到达了非常靠近N但是没有超过N(N是接近整数最大值的大小),然后step*2那么就会越界整数最大值变成负，上面的while(步长<N)就无法判断；
          所以需要防止溢出：所以如果步长mergeSize > N/2 那么下一步mergeSize一定会大于N，所以有溢出风险。
          只要mergeSize<=N/2，那么一定不会溢出.
           */
            if(step> N/2){ //注意是mergeSize > N/2 不是mergeSzie >=N/2，因为N/2是向下取整
                //比如17个数字，步长变化是1 2 4 8 16,如果是 17/2 = 8 = N/2就退出，那么就会跳过16这一步步长的merge
                //当前来到step=16步长了，已经大于N/2了，那么直接结束，因为16步长上一步已经merge了，下面在2倍肯定超过N了，不用排序了
                break;
            }
//            mergeSize <<= 1; //步长每次乘2
            step= step*2;
        }
    }



int main(){
    int n;

    scanf("%d",&n);
    int * q = new int [n]; //使用动态分配内存的数组
    for(int i = 0;i<n;++i){
        scanf("%d",&q[i]);
    }
    mergeSort1(q,n);
    // mergesort2(q,n);
    for(int i = 0;i<n;++i){
        printf("%d ",q[i]);
    }
    delete q;
    return 0;
}