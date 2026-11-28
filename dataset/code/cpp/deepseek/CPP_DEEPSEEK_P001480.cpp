#include <iostream>
#include <vector>

using namespace std;

int main() {
    string s;
    cin >> s;

    vector<int> last(26, 0);
    for (int i = 0; i < s.length(); ++i) {
        last[s[i] - 'a'] = i;
    }

    int anchor = 0, anchorLast = last[s[0] - 'a'];
    for (int i = 1; i < s.length(); ++i) {
        if (last[s[i] - 'a'] > anchorLast) {
            anchorLast = last[s[i] - 'a'];
        } else if (last[s[i] - 'a'] > anchor) {
            cout << anchorLast - anchor + 1 << endl;
            anchor = i;
            anchorLast = last[s[i] - 'a'];
        }
    }

    cout << anchorLast - anchor + 1 << endl;
    return 0;
}
This C++ solution reads the string from the standard input and computes the maximum size of each partition. It works by maintaining two pointers, `anchor` and `anchorLast`, which define the current partition. For each character in the string, it updates the `anchorLast` if the current character is more recent than the `anchor`. If it is the same or later, it computes the size of the current partition (`anchorLast - anchor + 1`), updates `anchor` to the current position, and updates `anchorLast` to the last occurrence of the current character. This way, it computes the sizes of all partitions and prints them.