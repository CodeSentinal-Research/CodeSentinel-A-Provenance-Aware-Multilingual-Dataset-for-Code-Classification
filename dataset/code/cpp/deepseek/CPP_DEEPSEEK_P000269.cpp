#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main() {
    string s;
    cout << "Enter a sentence: ";
    getline(cin, s);

    istringstream iss(s);
    string word;
    string reversed_sentence;

    while (iss >> word) {
        reversed_sentence = word + " " + reversed_sentence;
    }

    cout << "Reversed sentence: " << reversed_sentence << endl;

    return 0;
}