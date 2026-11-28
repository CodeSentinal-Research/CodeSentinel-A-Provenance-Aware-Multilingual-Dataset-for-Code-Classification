#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string pattern;
    cin >> pattern;

    vector<int> result;
    int current = 1;
    int increase = 1;
    int decrease = 2;

    for(char c : pattern) {
        if(c == 'I') {
            result.push_back(current);
            current += increase;
            increase++;
        } else {
            result.push_back(current);
            current -= decrease;
            decrease++;
        }
    }

    result.push_back(current);

    for(int i : result) {
        cout << i << " ";
    }

    return 0;
}