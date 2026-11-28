Here is the C++ code:

#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int main() {
    int q;
    cin >> q;
    set<int> s;
    for (int i = 1; i <= q; i++) {
        int type = i;
        cin >> type;
        if (type == 1) {
            int x;
            cin >> x;
            s.insert(x);
        } else {
            cout << *s.begin() << endl;
            s.erase(s.begin());
        }
    }
    return 0;
}

This program will read the number of operations Q, then for each operation, it will either insert a new number into the set or print the smallest number from the set. The set is used as a min heap, so the smallest number is always at the top.