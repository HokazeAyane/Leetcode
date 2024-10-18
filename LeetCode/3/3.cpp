#include <iostream>
#include <unordered_map>
#include <string>

int lengthOfLongestSubstring(const std::string& s){
    std::unordered_map<char,int> charIndexMap;
    int maxLength = 0;
    int start = 0;

    for(int end =0; end < s.length(); ++end){
        char currentChar = s[end];

        //在 unordered_map 中
        // find(currentChar): 返回指向键为 currentChar 的元素的迭代器。如果 currentChar 在哈希表中存在，它指向这个元素；否则，指向 end()。

        // end(): 返回迭代器，该迭代器指向容器的末尾 之后 的一个位置，不表示任何有效元素。可以理解为“尽头的标记”。
        

        if(charIndexMap.find(currentChar) != charIndexMap.end()){
            start = std::max(start, charIndexMap[currentChar]+1);
        }

        charIndexMap[currentChar] = end;
        maxLength = std::max(maxLength,end-start+1);
    }
    return maxLength;
}

int main() {
    std::string s1 = "abcabcbb";
    std::string s2 = "bbbbb";
    std::string s3 = "pwiopnnkew";

    std::cout << "Length of longest substring without repeating characters in 'abcabcbb': " << lengthOfLongestSubstring(s1) << std::endl;
    std::cout << "Length of longest substring without repeating characters in 'bbbbb': " << lengthOfLongestSubstring(s2) << std::endl;
    std::cout << "Length of longest substring without repeating characters in 'pwwkew': " << lengthOfLongestSubstring(s3) << std::endl;

    return 0;
}
