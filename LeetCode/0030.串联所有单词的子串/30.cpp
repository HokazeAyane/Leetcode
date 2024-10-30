#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution{
public:
    vector<int> findSubstring(string s, vector<string>& words){
        vector<int> result;
        if(s.empty() || words.empty() || words[0].empty()) return result;

        int wordLength = words[0].size();
        int wordCount = words.size();
        int substringLength = wordLength * wordCount;

        if (s.size() < substringLength) return result;

        unordered_map<string,int> wordFreq;
        for(const string& word : words){
            wordFreq[word]++;
        }

        // for(int i = 0; i<= s.size() - substringLength; ++i){
        //     unordered_map<string,int> seen;
        //     int j =0;

        //     while(j< wordCount){
        //         string word = s.substr(i+j*wordLength,wordLength);
        //         if(wordFreq.find(word) != wordFreq.end()){
        //             seen[word]++;
        //             if(seen[word] > wordFreq[word]){
        //                 break;
        //             }
        //         }else{
        //             break;
        //         }
        //         j++;
        //     }
        //     if( j == wordCount){
        //         result.push_back(i);
        //     }
        // }

        //滑动窗口
        for(int offset = 0; offset < wordLength; ++offset){
            unordered_map<string,int> seen;
            int start = offset, matchedWords = 0;

            for(int end = offset; end <=s.size() -wordLength; end +=wordLength){
                string word = s.substr(end,wordLength);

                if(wordFreq.find(word) != wordFreq.end()){
                    seen[word]++;
                    matchedWords++;

                    while(seen[word] > wordFreq[word]){
                        string startWord = s.substr(start,wordLength);
                        seen[startWord]--;
                        matchedWords--;
                        start += wordLength;
                    }

                    if(matchedWords == wordCount){
                        result.push_back(start);
                    }
                }else{
                    seen.clear();
                    matchedWords = 0;
                    start = end + wordLength;
                }
            }
        }
        return result;
    }
};