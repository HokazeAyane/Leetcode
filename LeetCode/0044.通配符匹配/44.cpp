#include <vector>

bool isMatch(string s ,string p){
    int m = p.size(), n = s.size();
    vector<vector<bool>> dp (m+1,vector<bool>(n+1,false));
    dp[0][0] = true;

    for(int i = 1; i<= m; i++){
        if(p[i-1] == '*') dp[i][0] = dp[i-1][0];
    }
    
    for(int i =1; i <= m; i++){
        for(int j =1; j <=n; j++){
            if(p[i-1] == '*'){
                dp[i][j] = dp[i-1][j] || dp[i][j-1]; //查看在 '*' 出现之前，字符串 s 和模式 p 是否已经匹配 ||查看在 '*' 匹配了前一个字符之后，s 的前 j-1 个字符是否与 p 的前 i 个字符匹配。

            }else if(p[i-1] =='?' || p[i-1] == s[j-1]){
                dp[i][j] = dp[i-1][j-1];
            }
            
        }
    }

    return dp[m][n];

}
