#include <iostream>
#include <stack>
#include <queue>

using namespace std;

bool checkStackPermutation(int n, int input[], int output[]) {
    stack<int> s;
    queue<int> q;

    for (int i = 0; i < n; i++) {
        q.push(input[i]);
    }

    for (int i = 0; i < n; i++) {
        s.push(q.front());
        q.pop();
        if (s.top() != output[i]) {
            return false;
        }
    }

    return true;
}

int main() {
    int n;
    cin >> n;
    int input[n], output[n];

    for (int i = 0; i < n; i++) {
        cin >> input[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> output[i];
    }

    if (checkStackPermutation(n, input, output)) {
        cout << "True";
    } else {
        cout << "False";
    }

    return 0;
}