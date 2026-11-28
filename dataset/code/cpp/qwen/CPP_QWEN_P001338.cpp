#include <iostream>
#include <vector>
#include <string>
using namespace std;

void generateSequential(int low, int high, vector<int>& result) {
    for (int i = 1; i <= 9; ++i) {
        string s = to_string(i);
        int num = i;
        while (num <= high) {
            if (num >= low) result.push_back(num);
            int lastDigit = num % 10;
            if (lastDigit == 9) break;
            num = num * 10 + (lastDigit + 1);
        }
    }
}

int main() {
    int low, high;
    cin >> low >> high;
    vector<int> result;
    generateSequential(low, high, result);
    
    for (int num : result) {
        cout << num << endl;
    }
    return 0;
}
