//最后计算结果要用long存储，int溢出
//另外左程云书上讲的小和是小于，这里是小于等于
#include <iostream>
using namespace std;
const int N  = 1e5+10;
int arr[N];
using ll = long ;
ll merge(int *arr,int L,int M,int R)   {
    int p1 = L,p2 = M+1,N = R-L+1,i = 0;
    ll  ans = 0;
    int * tmp = new int [N];
    //merge前左右数组都是[有序]的，这个条件可以方便快速求出小和
    while (p1<= M && p2<=R){
        ans += arr[p1]  <=  arr[p2]? arr[p1] * (R-p2+1) :0;
        //arr[p1]小于arr[p2],则arr[p1]小于p2及其后面所有的数，即R-p2+1个
        tmp[i++] =  arr[p1]  <= arr[p2] ? arr[p1++] : arr[p2++];
        //注意：比较时候归并排序是arr[p1]<=arr[p2],这里求小和需要用arr[p1]<arr[p2]
        //当arr[p1]>=arr[p2],先移动arr[p2]去tmp，因为数组是递增的，然后arr[p1]才可能小于p2后面的数，才能求小和;
        //即：只关心左边的数是不是小于右边的数
    } //while结束表示二组其中一个空了，那把另外一个拷贝到tmp数组即可
    while (p1<=M ){
        tmp[i++] = arr[p1++];
    }
    while (p2<=R){
        tmp[i++] = arr[p2++];
    }
    //最后有序数组tmp拷贝会arr数组，注意arr数组是从L开始的
    for(i = 0;i<N;++i){
        arr[L+i] = tmp[i];
    }
    return ans;
}

ll findSmallSum(int *arr,int L,int R){
    if(L>=R){
        return 0;
    }
    int M = L+(R-L)/2;
    return findSmallSum(arr,L,M)//左边递归排序过程中计算小和
    + findSmallSum(arr,M+1,R)//右边递归排序过程中计算小和
    + merge(arr,L,M,R);//左右组merge过程中计算小和
}
ll sm(int *arr,int L,int R){
    if(arr == nullptr || L==R){
        return 0;
    }
    return findSmallSum(arr, L, R);
}
int main(){
    std::ios::sync_with_stdio(false); //不要和标准输入同步，速度就快了
    int n;
    cin>>n;
    for(int i =1;i<=n;++i){
        cin>>arr[i];
    }
    ll  smallSum = sm(arr,1,n);
    cout<<smallSum<<endl;
    return  0;
}
