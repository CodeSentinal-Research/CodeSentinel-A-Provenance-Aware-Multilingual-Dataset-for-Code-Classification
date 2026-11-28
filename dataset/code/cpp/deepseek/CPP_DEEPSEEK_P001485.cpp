#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    string name, typed;
    cin >> name >> typed;

    int i = 0, j = 0;
    while (i < name.size() && j < typed.size()) {
        if (name[i] == typed[j]) {
            i++;
            j++;
        }
        else if (j > 0 && typed[j-1] == typed[j]) {
            j--;
        }
        else {
            break;
        }
    }

    if (i == name.size()) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}