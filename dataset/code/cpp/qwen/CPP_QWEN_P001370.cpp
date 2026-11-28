#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void findMaxNumber(string& num, int k, int index, string& maxNum) {
    if (k == 0 || index == num.length()) {
        if (num > maxNum) maxNum = num;
        return;
    }
    
    char maxChar = num[index];
    for (int i = index + 1; i < num.length(); ++i) {
        if (num[i] > maxChar) maxChar = num[i];
    }
    
    if (maxChar != num[index]) {
        for (int i = index + 1; i < num.length(); ++i) {
            if (num[i] == maxChar) {
                swap(num[index], num[i]);
                findMaxNumber(num, k - 1, index + 1, maxNum);
                swap(num[index], num[i]);
            }
        }
    } else {
        findMaxNumber(num, k, index + 1, maxNum);
    }
}

int main() {
    string num;
    int k;
    cin >> num >> k;
    string maxNum = num;
    findMaxNumber(num, k, 0, maxNum);
    cout << maxNum << endl;
    return 0;
}
