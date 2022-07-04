class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        for(int i = n-1;i>=0;--i){
            //【从个位开始，给这一位加1后模10结果是否为0，如果是0那么继续看上一位，如果不为0那么直接返回】
            digits[i] = (digits[i]+1)%10;
            if(digits[i] !=0){
                return digits;
            }
        }
        //【循环退出表示长度加1了，那么开辟新数组同时将最高位置1，其他位置0】
        digits = vector<int>(n+1,0);
        digits[0]=1;
        return digits;
    }
};