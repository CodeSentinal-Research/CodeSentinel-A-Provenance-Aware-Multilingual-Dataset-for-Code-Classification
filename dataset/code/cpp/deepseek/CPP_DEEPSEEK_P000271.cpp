#include <iostream>
#include <string>

using namespace std;

bool areRotations(string s1, string s2) {
    if (s1.length() != s2.length())
        return false;
        
    string temp = s1 + s1;
    
    if (temp.find(s2) != string::npos)
        return true;
        
    return false;
}

int main() {
    string s1, s2;
    cout << "Enter the first string: ";
    cin >> s1;
    cout << "Enter the second string: ";
    cin >> s2;

    if (areRotations(s1, s2))
        cout << "Yes";
    else
        cout << "No";

    return 0;
}
This C++ program first checks if the two strings are of the same length. If not, it returns false. If they are of the same length, it concatenates the first string to itself to form a longer string. Then, it checks if the second string is a substring of the longer string. If it is, it returns true; otherwise, it returns false.