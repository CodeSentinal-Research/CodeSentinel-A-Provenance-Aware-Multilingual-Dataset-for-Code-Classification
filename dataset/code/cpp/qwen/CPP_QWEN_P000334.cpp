#include <iostream>
#include <string>
using namespace std;

int main() {
    string source, target;
    cin >> source >> target;
    int res = 0;
    int i = 0;
    while (i < target.size()) {
        int j = 0;
        while (j < source.size() && i < target.size()) {
            if (source[j] == target[i]) i++;
            j++;
        }
        if (i == 0) { cout << -1 << endl; return 0; }
        res++;
    }
    cout << res << endl;
    return 0;
}
