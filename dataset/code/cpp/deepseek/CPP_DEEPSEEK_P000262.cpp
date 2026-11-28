#include <iostream>
using namespace std;

int firstNonRepeatingCharacter(string S) {
    int count[256] = {0};
    for(int i=0; i<S.length(); i++)
        count[S[i]]++;
    for(int i=0; i<S.length(); i++) {
        if(count[S[i]]==1)
            return i;
    }
    return -1;
}

int main() {
    string S;
    cout << "Enter a string: ";
    cin >> S;
    int res = firstNonRepeatingCharacter(S);
    if(res != -1)
        cout << "The first non-repeating character in the string is: " << S[res] << endl;
    else
        cout << "There are no non-repeating characters in the string." << endl;
    return 0;
}