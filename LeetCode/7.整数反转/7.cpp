#include <iostream>
#include <limits.h>

int reverse(int x) {
    int result = 0;
    while (x != 0) {
        int pop = x % 10;  // 取出最后一位
        x /= 10;
        
        // 检查即将发生的溢出情况  INT_MAX（2147483647） INT_MIN（-2147483648）
        if (result > INT_MAX / 10 || (result == INT_MAX / 10 && pop > 7)) return 0;
        if (result < INT_MIN / 10 || (result == INT_MIN / 10 && pop < -8)) return 0;
        
        result = result * 10 + pop;
    }
    return result;
}

int main() {
    int x = 123;
    std::cout << "Reversed: " << reverse(x) << std::endl;
    x = -123;
    std::cout << "Reversed: " << reverse(x) << std::endl;
    x = 120;
    std::cout << "Reversed: " << reverse(x) << std::endl;
    x = 0;
    std::cout << "Reversed: " << reverse(x) << std::endl;
    return 0;
}
