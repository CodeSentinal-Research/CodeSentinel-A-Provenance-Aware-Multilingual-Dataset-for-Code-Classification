#include <iostream>
#include <vector>
using namespace std;

void constructSequence(int n, int index, vector<int>& result, vector<bool>& used) {
    if (index == 2 * n - 1) {
        for (int i = 0; i < result.size(); ++i) {
            if (i > 0) cout << " ";
            cout << result[i];
        }
        cout << endl;
        exit(0);
    }
    
    if (result[index] != 0) {
        constructSequence(n, index + 1, result, used);
        return;
    }
    
    for (int num = n; num >= 1; --num) {
        if (used[num]) continue;
        if (num == 1) {
            result[index] = 1;
            used[1] = true;
            constructSequence(n, index + 1, result, used);
            used[1] = false;
            result[index] = 0;
        } else {
            int nextPos = index + num + 1;
            if (nextPos < 2 * n - 1 && result[nextPos] == 0) {
                result[index] = num;
                result[nextPos] = num;
                used[num] = true;
                constructSequence(n, index + 1, result, used);
                used[num] = false;
                result[index] = 0;
                result[nextPos] = 0;
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> result(2 * n - 1, 0);
    vector<bool> used(n + 1, false);
    constructSequence(n, 0, result, used);
    return 0;
}
