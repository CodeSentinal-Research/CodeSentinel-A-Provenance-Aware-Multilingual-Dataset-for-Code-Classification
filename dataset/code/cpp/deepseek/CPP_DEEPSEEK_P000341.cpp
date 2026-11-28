Here is the C++ code for your problem:

#include <iostream>
using namespace std;

int main() {
    string firstWord, secondWord, targetWord;
    cout << "Enter first word: ";
    cin >> firstWord;
    cout << "Enter second word: ";
    cin >> secondWord;
    cout << "Enter target word: ";
    cin >> targetWord;

    int sum = (firstWord[0] + secondWord[0] + targetWord[0]) - 255;

    if (sum == firstWord.size() + secondWord.size()) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}

This code will prompt you to enter three words. It will then calculate the sum of the ASCII values of the first two characters of each word and subtract 255 from the sum to get the ASCII value of '0' (which is the ASCII value for the character '0'). This sum is then compared to the sum of the lengths of the three words. If they are equal, it will print "Yes", otherwise it will print "No".