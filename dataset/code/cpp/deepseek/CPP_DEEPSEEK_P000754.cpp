#include <iostream>
#include <algorithm>
using namespace std;

void swapCase(char &c) {
    if(isupper(c))
        c = tolower(c);
    else
        c = toupper(c);
}

void permute(string s, int start, int end) {
    if (start == end) {
        swapCase(s[start]);
        cout << s << endl;
        swapCase(s[start]);
        return;
    }

    for (int i = start; i <= end; i++) {
        swap(s[start], s[i]);
        permute(s, start + 1, end);
        swap(s[start], s[i]);  
    }
}

int main() {
    string s;
    cin >> s;
    int n = s.size();
    permute(s, 0, n - 1);
    return 0;
}