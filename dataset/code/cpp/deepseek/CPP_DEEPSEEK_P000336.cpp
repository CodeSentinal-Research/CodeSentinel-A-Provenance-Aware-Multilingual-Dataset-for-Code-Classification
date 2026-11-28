#include <iostream>
#include <algorithm>

using namespace std;

bool checkPalindrome(string str) {
    int start = 0;
    int end = str.size() - 1;

    while (start < end) {
        if (str[start] != str[end])
            return false;
        start++;
        end--;
    }

    return true;
}

bool splitAndFormPalindrome(string A, string B) {
    string combined = A + B;
    if (!checkPalindrome(combined))
        return false;

    int len = A.size() + B.size();

    if (len % 2 != 0)
        return false;

    len /= 2;

    if (checkPalindrome(A.substr(0, len)) && checkPalindrome(B.substr(0, len)))
        return true;

    return false;
}

int main() {
    string A, B;
    cin >> A >> B;

    if (splitAndFormPalindrome(A, B))
        cout << "Yes";
    else
        cout << "No";

    return 0;
}
This C++ code first checks if the combined string can form a palindrome. If not, it returns "No". If it can form a palindrome, it checks if the prefixes and suffixes can also form a palindrome. If either prefix or suffix can't form a palindrome, it returns "No". Otherwise, it returns "Yes".