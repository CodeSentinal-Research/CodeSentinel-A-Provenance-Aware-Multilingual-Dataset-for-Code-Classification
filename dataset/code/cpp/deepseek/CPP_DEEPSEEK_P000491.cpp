#include <iostream>
#include <vector>

using namespace std;

vector<string> buildArray(int m, int n, vector<int> target) {
    vector<string> operations;
    int current = 1;
    int target_index = 0;

    while (m-- > 0) {
        if (current == target[target_index]) {
            operations.push_back("Push");
            target_index++;
            if (target_index == target.size()) {
                target_index = 0;
            }
        } else {
            operations.push_back("Push");
            operations.push_back("Pop");
        }
        current++;
    }

    return operations;
}

int main() {
    int m, n;
    cin >> m >> n;

    vector<int> target;
    for (int i = 0; i < m; i++) {
        int val;
        cin >> val;
        target.push_back(val);
    }

    vector<string> operations = buildArray(m, n, target);

    for (string operation : operations) {
        cout << operation << endl;
    }

    return 0;
}