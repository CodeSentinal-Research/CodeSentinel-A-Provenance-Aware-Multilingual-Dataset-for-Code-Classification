#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, power;
    cin >> n >> power;

    vector<int> tokens(n);
    for (int& token : tokens) {
        cin >> token;
    }

    sort(tokens.begin(), tokens.end());

    int maxScore = 0;
    int left = 0, right = n - 1;

    while (left <= right) {
        if (power >= tokens[left]) {
            power -= tokens[left];
            maxScore++;
            left++;
        } else if (power >= tokens[right]) {
            power -= tokens[right];
            maxScore++;
            right--;
        } else {
            break;
        }
    }

    cout << maxScore << endl;

    return 0;
}