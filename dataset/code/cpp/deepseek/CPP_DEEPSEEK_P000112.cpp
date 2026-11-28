#include <iostream>
#include <set>
#include <iterator>
using namespace std;

int main() {
    int n;
    cin >> n;

    set<int> s;

    for(int i = 0; i < n; i++) {
        int num;
        cin >> num;
        s.insert(num);
    }

    if(s.size() < 2) {
        cout << -1 << endl;
    } else {
        set<int>::iterator it;
        it = s.begin();
        std::advance(it, 1);
        cout << *it << endl;
    }

    return 0;
}