#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int m;
    cin >> m;
    vector<string> words(m);
    for (int i = 0; i < m; i++) cin >> words[i];
    string s;
    cin >> s;
    int count = 0;
    for (const string& w : words) {
        if (s.find(w) == 0) count++;
    }
    cout << count << endl;
    return 0;
}
