#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    string s;
    cin >> s;
    
    int i = 0;
    int j = s.size() - 1;
    
    while (i < j) {
        if (s[i] != 'a' && s[i] != 'A' && s[i] != 'e' && s[i] != 'E' && s[i] != 'i' && s[i] != 'I' && s[i] != 'o' && s[i] != 'O' && s[i] != 'u' && s[i] != 'U') {
            i++;
            continue;
        }
        if (s[j] != 'a' && s[j] != 'A' && s[j] != 'e' && s[j] != 'E' && s[j] != 'i' && s[j] != 'I' && s[j] != 'o' && s[j] != 'O' && s[j] != 'u' && s[j] != 'U') {
            j--;
            continue;
        }
        swap(s[i], s[j]);
        i++;
        j--;
    }
    
    cout << s << endl;
    
    return 0;
}