#include <iostream>
#include <string>
#include <climits>

using namespace std;

int myAtoi(string s){
    int i =0, n = s.length();
    //去掉空格
    while(i < n &&s[i] == ' '){
        i++;   
    }

    //检查符号
    int sign = 1;
    if(i < n &&(s[i] == '-' || s[i] == '+')){
    sign = (s[i] == '-') ? -1 : 1;
    i++;
    }
    
    //读取数字
    long long result = 0;
    while( i< n && isdigit(s[i])){
        result = result *10 + (s[i] - '0');
        //溢出
        if(result* sign >=INT_MAX) return INT_MAX;
        if(result* sign <=INT_MIN) return INT_MIN;
        i++;
    }
    //static_cast<int> 是一种类型转换操作，确保结果从 long long 转换为 int 类型。
    return static_cast<int>(result * sign);
}

int main() {
    cout << myAtoi("42") << endl;          // 输出 42
    cout << myAtoi("   -042") << endl;     // 输出 -42
    cout << myAtoi("1337c0d3") << endl;    // 输出 1337
    cout << myAtoi("0-1") << endl;         // 输出 0
    cout << myAtoi("words and 987") << endl; // 输出 0

    return 0;
}

