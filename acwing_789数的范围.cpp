#include <iostream>
using namespace std;
const int N = 1e6+10;
int arr[N];
int main(){
    std::ios::sync_with_stdio(false);
    int n,q;
    cin>>n>>q;
    for(int i = 0;i<n;++i){
        cin>>arr[i];
    }
    while (q--){
        int k;
        cin>>k;
        int l = 0,r = n-1;
        while (l<r){
            int mid = l+(r-l)/2;
            if(arr[mid] >= k) r = mid; //大于等于x，找左边界(mid可能取到答案)
            else l = mid+1;
        } //循环结束是l==r
        if(arr[l] !=k){
            cout<<"-1 -1"<<endl;
        }else {
            cout<<l<<" ";
            l = 0,r = n-1;
            while (l<r){
                // int mid  = 1+l+(r-l)/2;
                int mid = l+(r-l+1)/2;
                //为了防止死循环，当l=mid时候，上面求mid要加上1
                if(arr[mid]<=k)   l = mid; //小于等于x找右边界
                else  r = mid-1;
            }
            cout<<l<<endl;
        }
    }
    return  0;
}
