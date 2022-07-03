class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
       
        int n = 0;
        for(int i = 0;i<nums.size();++i)`){
            if( i==0 || nums[i]!=nums[i-1]){ 
                
                nums[n] = nums[i];
                ++n;
            }
        }
        return n;
    }
    //16.48
};

class Solution {
public:
		 //题目给的是有序数组去重，还要保序;
        //保序操作数组模板如下:
        //【过滤器原则:什么时候要，把要的操作进行】
    int removeDuplicates(vector<int>& nums) {
       int k = 0,i = 0;
       while(i<nums.size()){//先遍历数组所有元素
           //什么时候要，什么时候不要？
		  
           if(i == 0 || nums[i]  != nums[i-1]){
               nums[k++] = nums[i++];
			    //过滤条件:如果是第一个数那么要;如果当前数和前面数不一样，那么要当前数
				//把要的数放到Nums里面，n是用来存放放的下标
           }else {
               ++i;
           }
       }
       return k; //题目返回是总共多少个数；
	   //k下标正好代表前面0~k-1要的数
    }
};