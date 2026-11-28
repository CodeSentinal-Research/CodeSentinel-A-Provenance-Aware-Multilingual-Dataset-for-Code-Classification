#include <iostream>
using namespace std;

int main() {
    string word;
    cin >> word;
    if(isupper(word[0])) {
        for(int i = 1; i < word.size(); i++) {
            if(islower(word[i])) {
                cout << "No";
                return 0;
            }
        }
    } else {
        for(int i = 1; i < word.size(); i++) {
            if(isupper(word[i])) {
                cout << "No";
                return 0;
            }
        }
    }
    cout << "Yes";
    return 0;
}