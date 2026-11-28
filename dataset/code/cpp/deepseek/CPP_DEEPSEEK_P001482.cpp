#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int N, Power;
    cin >> N >> Power;

    vector<int> tokens(N);
    for (int i = 0; i < N; i++) {
        cin >> tokens[i];
    }

    sort(tokens.begin(), tokens.end());

    int maxScore = 0;
    int left = 0;
    int right = N - 1;

    while (left <= right) {
        if (Power >= tokens[left]) {
            Power -= tokens[left];
            maxScore++;
            left++;
        } else if (left == right) {
            break;
        } else {
            Power += tokens[right];
            maxScore++;
            right--;
        }
    }

    cout << maxScore << endl;

    return 0;
}