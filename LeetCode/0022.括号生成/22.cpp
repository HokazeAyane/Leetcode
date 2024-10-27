#include <vector>
#include <string>
#include <iostream>

using namespace std;
//回溯
void backtrack(vector<string>& result, string current, int left ,int right,int n){
    if(current.length() == 2 * n){
        result.push_back(current);
        return;
    }
    if(left < n){
        backtrack(result,current + "(", left + 1, right,n);
        
    }
    if(right < left){
        backtrack(result,current + ")", left, right+1,n);
                                                                                               
    }
}

vector<string> generateParentheses(int n){
    vector<string> result;
    backtrack(result,"",0,0,n);
    return result;
}




int main() {
    int n = 3;
    vector<string> result = generateParentheses(n);
    
    for (const string& s : result) {
        cout << s << endl;
    }

    return 0;
}


