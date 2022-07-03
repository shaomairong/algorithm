class Solution {
public:
    void moveZeroes(vector<int>& nums) { //依旧是保序操作数组
        int k = 0 ,i = 0;
        while(i<nums.size()){ //遍历数组
            if(nums[i]!=0){ //什么时候要？非0要，0不要
            //k记录要的元素放的下标，i遍历所有元素；如果非0元素那么放入k指向的下标，k移动
                nums[k++] = nums[i++];
            }else {
                ++i;
            }
        }
        while(k<nums.size()){ //将最后那些位置全部给0
            nums[k++] = 0;
        }
    }
};
