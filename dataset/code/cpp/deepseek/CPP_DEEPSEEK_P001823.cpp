#include <iostream>
#include <stack>
#include <vector>
using namespace std;

bool isValidPostorder(vector<int> &sequence) {
    stack<int> s;
    int root = INT_MAX;

    for (int i = sequence.size() - 1; i >= 0; --i) {
        if (sequence[i] > root) {
            return false;
        }

        while (!s.empty() && sequence[i] > s.top()) {
            root = s.top();
            s.pop();
        }

        s.push(sequence[i]);
    }

    return true;
}

int main() {
    int n;
    cin >> n;

    vector<int> sequence(n);
    for (int &i : sequence) {
        cin >> i;
    }

    if (isValidPostorder(sequence)) {
        cout << "YES";
    } else {
        cout << "NO";
    }

    return 0;
}