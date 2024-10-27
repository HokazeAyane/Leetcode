//-回溯-哈希表
#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 数字到字母的映射表
const vector<string> digitToLetters = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
void backtrack(const string& digits, int index, string& current, vector<string>& result){
    if(index == digits.size()){
        result.push_back(current);
        return;
    }

    int digit = digits[index] -'0';
    const string& letters = digitToLetters[digit];

    for(char letter : letters){
        current.push_back(letter);
        backtrack(digits,index + 1 ,current ,result);
        current.pop_back(); //回溯
    }
}

vector<string> letterCombinations(string digits){
    if(digits.empty()) return {};
    vector<string> result;
    string current;
    backtrack(digits,0,current,result);
    return result;
}

int main() {
    string digits1 = "23";
    vector<string> result1 = letterCombinations(digits1);
    for (const string& combination : result1) {
        cout << combination << " ";
    }
    cout << endl;

    string digits2 = "";
    vector<string> result2 = letterCombinations(digits2);
    for (const string& combination : result2) {
        cout << combination << " ";
    }
    cout << endl;

    string digits3 = "2";
    vector<string> result3 = letterCombinations(digits3);
    for (const string& combination : result3) {
        cout << combination << " ";
    }
    cout << endl;

    return 0;
}
