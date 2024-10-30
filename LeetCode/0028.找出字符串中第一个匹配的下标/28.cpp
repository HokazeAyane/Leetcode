#include <string>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int lenHay = haystack.length();
        int lenNeed = needle.length();

        if (lenNeed == 0) return 0;

        for (int i = 0; i <= lenHay - lenNeed; ++i) {
         
            if (haystack.substr(i, lenNeed) == needle) {
                return i;
            }
        }
        return -1;
    }
};
