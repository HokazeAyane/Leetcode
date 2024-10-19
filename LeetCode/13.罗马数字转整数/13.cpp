#include <iostream>
#include <string>
#include <vector>
#include <unordered_map> 

using namespace std;

//贪心算法
    int  romanToInt(string& roman){
    unordered_map<char, int> roman_values = {
        {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
        {'C', 100}, {'D', 500}, {'M', 1000}
    };

    int total = 0;
    int n = roman.size();

    for(int i = 0; i < n; ++i){
        int value = roman_values[roman[i]];

        if(i <n-1 && value < roman_values[roman[i+1]]){
            total -= value;
        }else{
            total += value;
        }
    }
    return total;
}

int main() {
    string roman1 = "XXVII";
    string roman2 = "MCMXCIV";
    string roman3 = "IV";
    
    cout << "XXVII -> " << romanToInt(roman1) << endl;
    cout << "MCMXCIV -> " << romanToInt(roman2) << endl;
    cout << "IV -> " << romanToInt(roman3) << endl;
    
    return 0;
}



