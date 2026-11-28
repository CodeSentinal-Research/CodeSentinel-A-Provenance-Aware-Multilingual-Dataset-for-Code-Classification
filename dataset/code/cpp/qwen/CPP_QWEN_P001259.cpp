#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;
    
    int swaps = 0;
    int open = 0;
    
    for (char c : s) {
        if (c == '[') {
            open++;
        } else {
            open--;
        }
        
        if (open < 0) {
            swaps++;
            open = 1; // After swap, we have one open bracket
        }
    }
    
    cout << swaps << endl;
    return 0;
}
