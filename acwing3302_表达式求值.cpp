#include <iostream>
#include <stack>
#include <unordered_map>
using namespace  std;
stack<int> num; //操作数栈
stack<int> op ; //运算符栈
unordered_map<char,int >   h{{'+',1},{'-',1},{'*',2},{'/',2}};
void eval(){//求值
    int a = num.top(); //第二个操作数
    num.pop();
    int b= num.top(); //第一个操作数
    num.pop();
    char p  = op.top(); //操作符
    op.pop();
    int r = 0; //结果
    //计算结果
    if(p == '+') r = b+a;
    else if (p == '-') r = b-a;
    else if (p == '*') r = b*a;
    else  r = b/a;
    num.push(r); //结果入栈
}
int main(){
    string  s;
    cin>>s; //读入表达式
    for(int i = 0;i<s.size();++i){ //遍历每个字符
        if(isdigit(s[i])){ //如果s[i]是数字，判断后面的字符是不是数字，组成整体的数值
            int x = 0,j = i;
            while (j< s.size() && isdigit(s[j])){
                x = x*10 + s[j]-'0';
                ++j;
            }
            num.push(x); //结果数字进栈
            i = j-1; //因为j现在指向的不是数字了，但是上面i会对i++，所以这里i要等于j-1,然后在++才是下一个要判断的字符
        }else if (s[i] == '('){ //左括号无优先级，直接入运算符栈
            op.push(s[i]);
        }else if(s[i] == ')'){ //右括号，那么要计算括号里面的
            while (op.top()!='('){//一直计算到op栈顶是左括号
                eval();
            }
            op.pop(); //左括号出栈
        }else { //s[i]是运算符+-/*,需要当前操作符判断优先级与栈顶运算符优先级比较
            while (op.size() && h[op.top()] >= h[s[i]]){//栈顶运算符优先级高，要先计算
                eval();
            }
            op.push(s[i]); //操作符入栈
        }
    }
    while (op.size()){
        eval(); //剩余的进行计算
    }
    cout<<num.top()<<endl; //最后操作数栈的栈顶元素就是计算结果
    return  0;
}
