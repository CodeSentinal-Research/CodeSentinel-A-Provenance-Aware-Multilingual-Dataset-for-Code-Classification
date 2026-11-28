#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

int main() {
    string text, broken;
    cin >> text >> broken;
    unordered_set<char> broken_set(broken.begin(), broken.end());
    int count = 0;
    bool can_type = true;
    for (char c : text) {
        if (c == ' ') {
            if (can_type) count++;
            can_type = true;
        } else if (broken_set.count(c)) {
            can_type = false;
        }
    }
    if (can_type && !text.empty() && text.back() != ' ') count++;
    cout << count << endl;
    return 0;
}
