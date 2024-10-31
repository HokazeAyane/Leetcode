#include <string>
#include <iostream>

using namespace std;

string countAndSay(int n){
    if(n == 1 ) return "1";

    string previous = "1";
    for(int i = 2; i <= n; ++i){
        string current = "";
        int count = 1;
        for(size_t j = 1; j< previous.size(); ++j){
            if(previous[j] == previous[j-1]){
                ++count;
            }else{
                current += to_string(count) + previous[j-1];
                count  = 1;
            }
        }
        current += to_string(count) + previous.back();
        previous = current;
    }
    return previous;
}