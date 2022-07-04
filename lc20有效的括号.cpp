class Solution {
public:
    bool isValid(string s) {
        for(char c : s){
            if(c == '(' || c=='[' || c =='{'){
                a.push(c);
            }else {
                if(a.empty()){
	//操作栈时候要判空；比如直接来一个"[",而此时栈空，如果弹栈就出错了
                    return false;
                }
                if(c == ')' && a.top()!='(') return false;
                if(c == ']' && a.top()!='[') return false;
                if(c == '}' && a.top()!='{') return false;
                a.pop();
            }
        }
        return  a.empty();
    }
    stack<char> a;
};