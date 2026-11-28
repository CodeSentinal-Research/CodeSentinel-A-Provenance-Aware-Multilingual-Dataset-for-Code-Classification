#include <iostream>
#include <string>
#include <map>

using namespace std;

string intToRoman(int num) {
    map<int, string> val = {{1, "I"}, {4, "IV"}, {5, "V"}, {9, "IX"}, {10, "X"}, 
                            {40, "XL"}, {50, "L"}, {90, "XC"}, {100, "C"}, {400, "CD"}, 
                            {500, "D"}, {900, "CM"}, {1000, "M"}};
    string roman = "";
    for(auto& it : val){
        while(num >= it.first){
            num -= it.first;
            roman += it.second;
        }
    }
    return roman;
}

int main() {
    int num;
    cout << "Enter an integer: ";
    cin >> num;
    if(num < 1 || num > 3999){
        cout << "Invalid input" << endl;
        return 0;
    }
    cout << "Roman numeral: " << intToRoman(num) << endl;
    return 0;
}