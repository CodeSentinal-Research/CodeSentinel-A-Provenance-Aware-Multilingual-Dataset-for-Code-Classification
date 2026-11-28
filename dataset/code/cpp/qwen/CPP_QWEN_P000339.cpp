#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    int v1 = 0, v2 = 0;
    for (int i = 0; i < n / 2; i++) {
        char c = tolower(s[i]);
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') v1++;
    }
    for (int i = n / 2; i < n; i++) {
        char c = tolower(s[i]);
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') v2++;
    }
    cout << (v1 == v2 ? "Yes" : "No") << endl;
    return 0;
}
