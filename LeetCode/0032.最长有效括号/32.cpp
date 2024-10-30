//-栈-动态规划

#include <stack>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

class Solution{
public:
    //栈
    int longestValidParentheses(string s){
        stack<int> stk;
        stk.push(-1); //计算长度
        int maxLength = 0;

        for(int i = 0; i < s.length(); ++i){
            if(s[i] == '('){
                stk.push(i);
            }else{
                stk.pop();
                if(stk.empty()){
                    stk.push(i);
                }else{
                    maxLength = max(maxLength, i - stk.top());
                }
            }
        }

        return maxLength;
    }

    //动态规划
    int longestValidParentheses1(string s) {
        int maxLength = 0;
        vector<int> dp(s.length(), 0);  // 创建 dp 数组并初始化为 0

        for (int i = 1; i < s.length(); ++i) {  // 从第二个字符开始遍历
            if (s[i] == ')') {  // 只处理 ')'
                if (s[i - 1] == '(') {  // 情况 1：前一个字符是 '('
                    dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;  // 直接匹配，长度加上前面部分的长度
                } else if (i - dp[i - 1] > 0 && s[i - dp[i - 1] - 1] == '(' ) {  // 情况 2：前一个字符是 ')'
                    dp[i] = dp[i - 1] + ((i - dp[i - 1] >= 2) ? dp[i - dp[i - 1] - 2] : 0) + 2;  // 连接前面的有效括号
                }
                maxLength = max(maxLength, dp[i]);  // 更新最大长度
            }
        }

        return maxLength;
    }
// 对于字符串 "(()))())("：

// 初始栈：[-1]
// 遍历过程：
// i = 0，字符 '('，栈变为 [-1, 0]
// i = 1，字符 '('，栈变为 [-1, 0, 1]
// i = 2，字符 ')'，弹出栈顶，栈变为 [-1, 0]，计算长度 2 - 0 = 2，更新 maxLength = 2
// i = 3，字符 ')'，弹出栈顶，栈变为 [-1]，计算长度 3 - (-1) = 4，更新 maxLength = 4
// i = 4，字符 ')'，栈为空，压入 4，栈变为 [4]
// i = 5，字符 '('，栈变为 [4, 5]
// i = 6，字符 ')'，弹出栈顶，栈变为 [4]，计算长度 6 - 4 = 2，maxLength 不变
// i = 7，字符 ')'，栈为空，压入 7，栈变为 [7]
// i = 8，字符 '('，栈变为 [7, 8]
// 最终，最长有效括号的长度是 4。

};