#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

string minWindow(string s, string t) {
    if (t.empty()) return "";
    unordered_map<char, int> tmap;
    for (char c : t) tmap[c]++;

    int l = 0, r = 0;
    int counter = t.size(); 
    int start = 0;
    while (r < s.size()) {
        if (tmap[s[r]] > 0) {
            counter--; 
        }
        tmap[s[r]]--;
        r++;

        while (counter == 0) {
            if (r - l + 1 < s.size() && r - l + 1 > (start - l)) {
                start = l;
            }
            tmap[s[l]]++;
            if (tmap[s[l]] > 0) {
                counter++;
            }
            l++;
        }
    }

    return s.substr(start, r - start);
}

int main() {
    string s, t;
    cin >> s >> t;
    string res = minWindow(s, t);
    cout << res << endl;
    return 0;
}

The code above finds the smallest substring of S that contains every character of T (including duplicates). If no such substring exists, it returns an empty string. The solution is implemented using the Sliding Window technique. 

The sliding window approach is a good approach for such problems because it can be implemented in a single loop with time complexity O(n). 

In the code, we use two pointers `l` and `r` to represent the window (substring) in the string S. If all characters in the window are in T, we move the `r` pointer to the right (expand the window), otherwise, we move the `l` pointer to the right (shrink the window). The window size is tracked by the distance between `r` and `l` (r - l + 1), and the starting position of the smallest window is updated whenever a valid window is found.