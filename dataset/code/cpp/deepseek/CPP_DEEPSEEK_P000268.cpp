#include <iostream>
#include <sstream>

using namespace std;

int main() {
    string S;
    getline(cin, S);

    istringstream iss(S);
    string word;
    int wordCount = 0;

    while (iss >> word) {
        wordCount++;
    }

    cout << wordCount;

    return 0;
}