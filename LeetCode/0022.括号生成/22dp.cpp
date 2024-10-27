#include <vector>
#include <string>
#include <iostream>

using namespace std;

// 动态规划
vector<string> generateParenthesesDP(int n){
    vector<vector<string>> dp(n+1);
    dp[0] = {""};

    for(int i =1; i <= n; i++){
        for(int j = 0; j < i ;j++){
            for(const string& left : dp[j]){
                for(const string& right : dp[i-j-1]){
                    dp[i].push_back("(" + left + ")" + right);
                }
            }
        }
    }
    return dp[n];
}


int main() {
    int n = 3;
    vector<string> result = generateParenthesesDP(n);
    for (const string& s : result) {
        cout << s << endl;
    }
    return 0;
}

