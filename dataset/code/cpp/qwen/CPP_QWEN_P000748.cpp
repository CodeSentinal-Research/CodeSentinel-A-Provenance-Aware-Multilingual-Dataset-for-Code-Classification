#include <iostream>
#include <string>
#include <vector>
using namespace std;

void generateDiceRolls(int target, string current, vector<string>& result) {
    if (target == 0) {
        result.push_back(current);
        return;
    }
    for (int i = 1; i <= 6; ++i) {
        if (target - i >= 0) {
            generateDiceRolls(target - i, current + to_string(i), result);
        }
    }
}

int main() {
    int target;
    cin >> target;
    vector<string> result;
    generateDiceRolls(target, "", result);
    
    for (const string& seq : result) {
        cout << seq << endl;
    }
    return 0;
}
