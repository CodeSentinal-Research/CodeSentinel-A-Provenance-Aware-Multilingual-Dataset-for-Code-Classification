#include <iostream>
#include <vector>
using namespace std;

int countArrangement(int N, vector<bool>& used, int pos) {
    if (pos > N) return 1;
    int count = 0;
    for (int i = 1; i <= N; ++i) {
        if (!used[i] && (i % pos == 0 || pos % i == 0)) {
            used[i] = true;
            count += countArrangement(N, used, pos + 1);
            used[i] = false;
        }
    }
    return count;
}

int main() {
    int N;
    cin >> N;
    vector<bool> used(N + 1, false);
    cout << countArrangement(N, used, 1) << endl;
    return 0;
}
