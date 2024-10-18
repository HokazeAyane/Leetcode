#include <iostream>
#include <string>
// 时间O(n^2)
using namespace std;
// 引用传递 常量性
string expandAroundCenter(const string& s,int left, int right){
    while(left >=0  &&right <s.size()  && s[left] == s[right]){  //扩展
        left--;
        right++;

    }
    return s.substr(left+1,right - left -1);  //调整起始位置和长度
}

string longestPalindrome(string s) {
    if (s.empty()) return "";
    
    string longest;
    
    for (int i = 0; i < s.size(); i++) {
        // 奇数长度的回文
        string oddPalindrome = expandAroundCenter(s, i, i);
        if (oddPalindrome.size() > longest.size()) {
            longest = oddPalindrome;
        }
        
        // 偶数长度的回文
        string evenPalindrome = expandAroundCenter(s, i, i + 1);
        if (evenPalindrome.size() > longest.size()) {
            longest = evenPalindrome;
        }
    }
    
    return longest;
}

int main() {
    string s1 = "babad";
    cout << "Longest Palindromic Substring of " << s1 << " is: " << longestPalindrome(s1) << endl;

    string s2 = "cabbad";
    cout << "Longest Palindromic Substring of " << s2 << " is: " << longestPalindrome(s2) << endl;

    return 0;
}
