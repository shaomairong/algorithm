int merge(int *arr,int L,int M,int R){
    //左组:L..M  右组:M+1..R
    int ans= 0;
    int windowR = M+1; //目前包含进来的数，是从[M+1,windowR)注意前闭后开区间,即不包含windowR
    for(int i = L;i<=M;++i){
        while (windowR <=R && arr[i] > 2*arr[windowR]){
            windowR++;
        }
        ans +=  windowR-(M+1); //因为不包含windowR，所以不需要加1
    }
    //上面是针对二个有序的左右组找出 左边大于右边二倍的数字有多少个，虽然是二层for但时间复杂度是O(N)，是滑动窗口(指针不回退)
    //下面把二个有序数组排好序，方便后面使用
    int * tmp = new int [R-L+1];
    int p1 = L,p2 = M+1,i = 0;
    while (p1<=M && p2 <=R){
        tmp[i++] = arr[p1] <=arr[p2] ? arr[p1++] :arr[p2++];
    }
    while (p1<=M){
        tmp[i++] = arr[p1++];
    }
    while (p2<=R){
        tmp[i++] =arr[p2++];
    }
    for(i = 0;i<R-L+1;++i){
        arr[L+i] = tmp[i];
    }
    return ans;

}
int process(int *arr,int L,int R){
    //process:找到左边大于右边二倍的数组同时完成排序
    if(L==R) return 0;
    int M = L+(R-L)/2;
    return process(arr,L,M) + process(arr,M+1,R) +merge(arr,L,M,R);
    //启发：当想求一个数左边右边怎么样的时候，可以思考归并排序的merge过程能不能快速完成任务？
}