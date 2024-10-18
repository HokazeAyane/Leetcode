#include <string>
#include <iostream>
#include <vector>

using namespace std;

string convert(const string& s, int numRows){
    if(numRows == 1 || numRows >=s.length()) return s;

    vector<string> rows(min(numRows,int(s.length())));
    int currentRow = 0;
    bool goingDown = false;

    for(char c : s){
        rows[currentRow] += c;
        if(currentRow == 0 || currentRow == numRows -1){
            goingDown = !goingDown;
        }
        currentRow += goingDown ? 1 : -1;
    }

    string result;
    for(string row : rows){
        result += row;
    }

    return result;
}

int main() {
    string s1 = "PAYPALISHIRING";
    string s2 = "ABCDEFGHIJ";
    int num1Rows = 3;
    int num2Rows = 4;
    string result1 = convert(s1, num1Rows);
    string result2 = convert(s2, num2Rows);
    cout <<"output:" << result1 <<endl;
    cout <<"output:" << result2 <<endl;
    // 输出结果: "PAHNAPLSIIGYIR"
    return 0;
}

