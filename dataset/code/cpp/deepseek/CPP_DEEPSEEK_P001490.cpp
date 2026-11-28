#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;
    int count = 0;
    int max_count = 0;
    char last_char = '\0';
    for(int i = 0; i < s.length(); i++) {
        if (s[i] == '0' && s[i] != last_char) {
            count++;
        } else if (s[i] == '1' && s[i] == last_char) {
            max_count = max(max_count, count);
            count = 1;
        } else {
            count = 1;
        }
        last_char = s[i];
    }
    max_count = max(max_count, count);
    cout << max_count << "\n";
    return 0;
}