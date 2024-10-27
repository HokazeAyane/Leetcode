#include <iostream>
#include <stack>
#include <unordered_map>

using namespace std;

bool isValid (string s){
    stack<char> stk;
    unordered_map<char,char> brackets = {
        {')','('},
        {']','['},
        {'}','{'}
    };

    for (char ch : s){
        if(brackets.count(ch)){
            if(!stk.empty() && stk.top() == brackets[ch]){
                stk.pop();
            }else{
                return false;
            }
        }else{
            stk.push(ch);
        }
    }
    return stk.empty();
   
}

int main() {
    string s1 = "()";
    string s2 = "()[]{}";
    string s3 = "(]";
    string s4 = "([])";

    cout << boolalpha;
    cout << "s1: " << isValid(s1) << endl;
    cout << "s2: " << isValid(s2) << endl;
    cout << "s3: " << isValid(s3) << endl;
    cout << "s4: " << isValid(s4) << endl;

    return 0;
}



// 示例 : s = "([])"
// 步骤1:

// 输入字符 '(', 非右括号，压入栈。
// 栈状态: ['(']
// 步骤2:

// 输入字符 '[', 非右括号，压入栈。
// 栈状态: ['(', '[']
// 步骤3:

// 输入字符 ']', 右括号，栈顶匹配弹出。
// 栈状态: ['(']
// 输入字符 ')', 右括号，栈顶匹配弹出。
// 栈状态: []
// 遍历结束，栈为空，返回 true.