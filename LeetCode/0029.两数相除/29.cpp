#include <cmath>
#include <limits>

class Solution {
public:
    int divide(int dividend, int divisor) {
        // 处理特殊情况，防止溢出
        //在 32 位有符号整数中，最小值是-2147483648，最大值是2147483647）。为了避免整数溢出，我们检测这种特殊情况并手动返回最大值 2147483647。
        if (dividend == std::numeric_limits<int>::min() && divisor == -1) {
            return std::numeric_limits<int>::max();
        }

        // 确定结果的符号
        bool positive = (dividend < 0) == (divisor < 0);

        // 使用 long long 防止越界
        long long m = std::abs(static_cast<long long>(dividend));
        long long n = std::abs(static_cast<long long>(divisor));

        long long result = 0;

        // 进行除法的主要逻辑
        while (m >= n) {
            long long temp = n, multiple = 1;
            while (m >= (temp << 1)) {
                temp <<= 1;
                multiple <<= 1;
            }
            m -= temp;
            result += multiple;
        }

        return positive ? result : -result;
    }
};
