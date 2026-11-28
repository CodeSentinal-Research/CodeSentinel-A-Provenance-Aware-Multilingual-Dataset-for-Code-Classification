#include <iostream>
#include <string>

using namespace std;

string removeVowels(string S) {
    string vowels = "aeiouAEIOU";

    for(int i = 0; i < vowels.length(); i++) {
        string::iterator it = S.begin();
        while ((it = S.find(vowels[i])) != S.end()) {
            S.erase(it);
        }
    }

    return S;
}

int main() {
    string S;
    cin >> S;
    cout << removeVowels(S);

    return 0;
}