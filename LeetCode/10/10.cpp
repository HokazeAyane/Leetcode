#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isMatch(const string& s, const string& p) {
    int m = s.size();
    int n = p.size();
    
    //dp[i][j] 表示字符串 s 的前 i 个字符和模式 p 的前 j 个字符是否匹配。
    vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
    
    // 空字符串和空模式匹配
    dp[0][0] = true;
    
    // 处理模式 p 的首项为 '*' 的情况
    for (int j = 1; j <= n; ++j) {
        if (p[j - 1] == '*') {
            dp[0][j] = dp[0][j - 2];
        }
    }

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (p[j - 1] == s[i - 1] || p[j - 1] == '.') {
                dp[i][j] = dp[i - 1][j - 1];
            } else if (p[j - 1] == '*') {
                dp[i][j] = dp[i][j - 2];
                if (p[j - 2] == s[i - 1] || p[j - 2] == '.') {
                    dp[i][j] = dp[i][j] || dp[i - 1][j];
                }
            }
        }
    }

    return dp[m][n];
}

int main() {
    cout << isMatch("aa", "a") << endl;    // 输出 false
    cout << isMatch("aa", "a*") << endl;   // 输出 true
    cout << isMatch("ab", ".*") << endl;   // 输出 true
    cout << isMatch("aab", "c*a*b") << endl;   // 输出 true
    cout << isMatch("abc", "***") << endl;   // 输出 true

    return 0;
}
