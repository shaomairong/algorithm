#include <iostream>
#include <unordered_map>
using namespace  std;
const int N = 1e5+10;
int arr[N];
int main(){
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i = 1;i<=n;++i){
        cin>>arr[i];
    }
    int ans = 0;
    unordered_map<int,int> map;
    /*遍历数组中的每一个元素arr[i],找到j使得双指针[j,i]维护的是以arr[i]结尾的最长连续不重复子序列，长度j-i+1,与ans比较更新即可;
     * 由于[j,i-1]是前一步得到的最长连续不重复子序列，如果[j,i]中有重复元素，一定是arr[i],因此右移动j直到arr[i]不重复为止;
     * j只能右移动剔除重复元素arr[i],因此j具有单调性
     */
    for(int i = 1,j=1;i<=n;++i){
        map[arr[i]] ++;
        while (map[arr[i]]>1){ //i当前指向的数遇见重复了
            map[arr[j]]--;
            ++j;
        }
        ans = std::max(ans,i-j+1);
    }
    cout<<ans<<endl;
    return 0;
}
