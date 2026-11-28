#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;
    
    char maxChar = s[0];
    int maxCount = 1;
    int currCount = 1;
    
    for (int i = 1; i < s.length(); ++i) {
        if (s[i] == s[i-1]) {
            currCount++;
        } else {
            if (currCount > maxCount || (currCount == maxCount && s[i-1] < maxChar)) {
                maxCount = currCount;
                maxChar = s[i-1];
            }
            currCount = 1;
        }
    }
    // Check last run
    if (currCount > maxCount || (currCount == maxCount && s.back() < maxChar)) {
        maxCount = currCount;
        maxChar = s.back();
    }
    
    cout << maxChar << " " << maxCount << endl;
    return 0;
}
