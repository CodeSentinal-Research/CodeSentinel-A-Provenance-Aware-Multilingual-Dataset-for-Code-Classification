#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> mapping = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

void generateCombinations(string data, string current="") {
    if(data.length() == 0) {
        cout << current << endl;
        return;
    }

    char first = data[0];
    string remaining = data.substr(1);

    for(char c : mapping[first - '0']) {
        generateCombinations(remaining, current + c);
    }
}

int main() {
    string phoneNumber;
    cin >> phoneNumber;

    sort(phoneNumber.begin(), phoneNumber.end());

    generateCombinations(phoneNumber);

    return 0;
}

This C++ code will provide all possible combinations of letters for a given phone number. The `mapping` array maps each digit to the corresponding set of letters. The `generateCombinations` function recursively generates the combinations by taking a character from the phone number string and appending it to the current combination.