#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<string> strs1(n);
    vector<string> strs2(n);

    for(int i = 0; i < n; i++) {
        cin >> strs1[i];
    }

    for(int i = 0; i < n; i++) {
        cin >> strs2[i];
    }

    bool equivalent = (strs1 == strs2);

    if(equivalent) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}