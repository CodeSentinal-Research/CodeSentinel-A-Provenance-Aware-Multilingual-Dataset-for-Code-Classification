#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;
    
    int balance = 0;
    int insertions = 0;
    
    for (char c : s) {
        if (c == '(') {
            balance++;
        } else {
            balance--;
        }
        
        if (balance < 0) {
            insertions++;
            balance = 0;
        }
    }
    
    insertions += balance;
    
    cout << insertions << endl;
    return 0;
}
