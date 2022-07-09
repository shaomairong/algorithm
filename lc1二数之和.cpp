//方法1：先把所有元素放入哈希表中
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> m;
        for(int i = 0;i<nums.size();++i){
            m.insert({nums[i],i}); //把所有数放入map中
        }
        for(int i = 0;i<nums.size();++i){
            int val  = target - nums[i];
            auto it = m.find(val);//在map中寻找这个数
            if(it!=m.end()){//如果map中有这个数
                if(it->second !=i){//且这个数不是自己
                //3,2,4 tar = 6,如果不加这一步判断那么就会输出00，实际是1,2
                    return {it->second,i};
                }
            }
        }
        return {-1,-1};
    }
};
//方法2：实际上本题不需要实现把所有元素放入哈希表中，可以边查找边放
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> m;
        for(int i = 0;i<nums.size();++i){
            auto it = m.find(target - nums[i]);
            if(it!=m.end()){
                return {it->second,i};
            }else{
                m.insert({nums[i],i});
            }
        }
        return {-1,-1};
    }
};
//方法3：如果题目说数组是有序的，那么就可以使用双指针的方法
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i = 0,j = nums.size()-1;
        while(i<j){
            int sum = nums[i] + nums[j];
            if(sum == target) return {i,j};
            else if(sum < target) ++i;
            else --j;
        }
        return {-1,-1};
    }
};