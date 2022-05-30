#include <iostream>
#include <queue>
using  namespace  std;
const int N = 1e6+10;
int arr[N];
int partition(int *arr,int L,int R){
    int i = L,j = R;
    int temp = arr[i];
    if(L<R){
        while (i<j){
            while (i<j && arr[j]>temp) --j;
            if(i<j){
                arr[i] =arr[j];
                ++i;
            }
            while (i<j  && arr[i] < temp) ++i;
            if(i<j){
                arr[j] =arr[i]  ;
                --j;
            }
        }//退出时i=j
        arr[i] = temp;
        return i;
    }
}
int randomPaitition(int *arr,int L,int R){
    int i = rand()%(R-L+1) +L;
    std::swap(arr[i],arr[L]);
    return partition(arr,L,R);
}
int quickFind(int *arr,int L,int R,int k) {
    int pivot = randomPaitition(arr,L,R);
    if(pivot == k){
        return arr[k];
    }else {
        return pivot < k? quickFind(arr,pivot+1,R,k) : quickFind(arr,L,pivot-1,k);
    }
}
int findkth(int *arr,int N,int k){
    std::priority_queue<int,vector<int>,std::less<int>> heap; //大顶堆
    for(int i =1;i<=N;++i){
        if(i<=k){ //前k个数建立大顶堆(找第k大建立大顶堆)
            heap.push(arr[i]);
        }else {
            if(arr[i] < heap.top()){ //如果当前值大于堆顶元素跳过；
            //当前值小于堆顶元素，堆顶元素(最大的)出去，当前值进队列
                heap.pop();
                heap.push(arr[i]);
            }
        }
    }
    return heap.top();
}
int main(){
    ios::sync_with_stdio(false);
    srand(time(0));
    int n,m;
    cin>>n>>m;
    for(int i =1;i<=n;++i){
        cin>>arr[i] ;
    }
    //寻找从小到大的第k个数
    // int ans = quickFind(arr,1,n,m);
    int ans = findkth(arr,n,m);
    cout<<ans<<endl;
    return  0;
}