// #include <iostream>
// bool isPalindrome(int x){
//     if(x < 0 || (x % 10 ==0 && x !=0)){
//         return false;
//     }

//     int reversedHalf = 0;
//     while(x > reversedHalf){
//         reversedHalf = reversedHalf* 10 + x%10;
//         x /=10;
//     }

//     return x == reversedHalf || x ==reversedHalf /10;
// }

// int main() {
//     int x1 = 121;
//     int x2 = -121;
//     int x3 = 10;

//     std::cout << isPalindrome(x1) << std::endl;  // 输出 true
//     std::cout << isPalindrome(x2) << std::endl;  // 输出 false
//     std::cout << isPalindrome(x3) << std::endl;  // 输出 false

//     return 0;
// }


#include <iostream>
#include <string>
#include <algorithm>

bool isPalindrome(int x) {
    std::string str = std::to_string(x);
    std::string reversedStr = str;
    
    std::reverse(reversedStr.begin(), reversedStr.end());
    
    return str == reversedStr;
}

int main() {
    int number = -12321;
    if (isPalindrome(number)) {
        std::cout << number << " is a palindrome." << std::endl;
    } else {
        std::cout << number << " is not a palindrome." << std::endl;
    }
    
    return 0;
}