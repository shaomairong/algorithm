#include <iostream>
#include <vector>
using namespace  std;
using l = long ; //int存储返回结果会溢出，用long即可
l merge(int *arr,int L,int M,int R){
    int N = R-L+1,p1 = M,p2 = R;
    l ans  = 0;
    //求逆序对是从后往前;小和是从前往后
    vector<int> tmp;
    tmp.reserve(N);
    int i = N-1;
    while (p1>=L && p2>=M+1) {
        ans += arr[p1] > arr[p2] ?  p2-(M+1)+1 : 0;
        tmp[i--] =  arr[p1] >arr[p2] ? arr[p1--] : arr[p2--];
    }
    while (p1>=L){
        tmp[i--] = arr[p1--];
    }
    while (p2>=M+1){
        tmp[i--] = arr[p2--];
    }
    for(i = 0;i<N;++i){
        arr[L+i]  = tmp[i];
    }
    return ans;
}
l findReversePair(int *arr,int L,int R)   {
    if(L>=R) return 0;
    int M = L+(R-L)/2;
    return findReversePair(arr,L,M)+ findReversePair(arr,M+1,R) + merge(arr,L,M,R);
}
const int N  = 1e6+10;
int arr[N];
int main(){
    int n;
    std::ios::sync_with_stdio(false);
    cin>>n;
    for(int i = 1;i<=n;++i){
        cin>>arr[i];
    }
    l  ans = findReversePair(arr,1,n); //寻找1~N之间的逆序对
    cout<<ans<<endl;
    return 0;
}
