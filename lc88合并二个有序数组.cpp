class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
      //nums1后面有很多空余空间，那么可以从后往前放
      int i = m-1,j = n-1;
      for(int k = m+n-1;k>=0;--k){
          //什么时候要nums2的元素？i<0(nums1下标出界了)或者j>=0 && nums2[j]<nums1[i]
          if(i<0 || (j>=0 && nums2[j]>= nums1[i])){
              nums1[k] = nums2[j--];
          }else {
              nums1[k] = nums1[i--];
          }
      }
    }
};