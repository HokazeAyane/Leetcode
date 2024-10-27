#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 贪心算法
string intToRoman(int num) {
    vector<pair<int, string>> roman_values = {
        {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, 
        {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"}, 
        {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
    };

    string roman;
    for (const auto& [value, symbol] : roman_values) {
        while (num >= value) {
            num -= value;
            roman += symbol;
        }
    }
    return roman;
}

int main() {
    int num1 = 3749;
    int num2 = 58;
    int num3 = 1994;

    cout << "3749 -> " << intToRoman(num1) << endl;
    cout << "58 -> " << intToRoman(num2) << endl;
    cout << "1994 -> " << intToRoman(num3) << endl;

    return 0;
}




// #include <iostream>
// #include <string>
// #include <vector>

// //贪心算法
// string intToRoman(int num){
//     vector<int> values = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
//     vector< string> symbols = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
//     string roman;
//     for(int i =0; i < values.size();i++){
//         while(num >= values[i]){
//             num -= values[i];
//             roman += symbols[i];
//         }
//     }
//     return roman;
// }

// int main(){
//     int num1 = 3749;
//     int num2 = 58;
//     int num3 = 1994;

//     cout <<"3749 ->" << intToRoman(num1) <<endl;
//     cout <<"58 ->" << intToRoman(num2) <<endl;
//     cout <<"1994 ->" << intToRoman(num3) <<endl;

//     return 0;
// }