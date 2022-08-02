//方法1：每次计算的字符串用参数传递，不需要还原现场
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        this->digits = digits;
        if(digits.empty()) return {};
        /*本题如果在纸上模拟，需要关注那些信息呢？
         * 依次考虑每个数字对于那个字母！所以index和字符串就是二个变化量
         */
        alphabet['2']="abc";
        alphabet['3']="def";
        alphabet['4']="ghi";
        alphabet['5']="jkl";
        alphabet['6']="mno";
        alphabet['7']="pqrs";
        alphabet['8']="tuv";
        alphabet['9']="wxyz";
        dfs(0,"");
        return ans;
    }
private:
    void dfs(int index,string str){
        if(index == digits.length()) {
            //每次当处理完时，在搜索树的叶子上面记录答案返回
            ans.push_back(str);
            return;
        }
        //是从一个数字选对应的字母集合中的一个来用
        for(char ch : alphabet[digits[index]]){
            dfs(index+1,str+ch);
        }
    }
    //从字符数字到字符串的映射
    unordered_map<char,string>  alphabet;
    string digits;
    vector<string> ans;
};
//2.方法2：每次计算的结果当作共享的，需要还原现场：
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        this->digits = digits;
        if(digits.empty()) return {};
        /*本题如果在纸上模拟，需要关注那些信息呢？
         * 依次考虑每个数字对于那个字母！所以index和字符串就是二个变化量
         */
        alphabet['2']="abc";
        alphabet['3']="def";
        alphabet['4']="ghi";
        alphabet['5']="jkl";
        alphabet['6']="mno";
        alphabet['7']="pqrs";
        alphabet['8']="tuv";
        alphabet['9']="wxyz";
        dfs(0);
        return ans;
    }
private:
    void dfs(int index){
        if(index == digits.length()) {
            //每次当处理完时，在搜索树的叶子上面记录答案返回
            ans.push_back(str);
            return;
        }
        //是从一个数字选对应的字母集合中的一个来用
        for(char ch : alphabet[digits[index]]){
            str.push_back(ch);
            dfs(index+1);
            str.pop_back(); //还共享变量str需要还原现场
        }
    }
    //从字符数字到字符串的映射
    unordered_map<char,string>  alphabet;
    string digits;
    vector<string> ans;
    string str;
};