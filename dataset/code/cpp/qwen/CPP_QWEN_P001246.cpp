#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, power;
    cin >> n >> power;
    vector<int> tokens(n);
    for (int i = 0; i < n; ++i) cin >> tokens[i];
    
    sort(tokens.begin(), tokens.end());
    
    int score = 0;
    int left = 0, right = n - 1;
    
    while (left <= right) {
        if (power >= tokens[left]) {
            power -= tokens[left];
            score++;
            left++;
        } else if (score > 0) {
            power += tokens[right];
            score--;
            right--;
        } else {
            break;
        }
    }
    
    cout << score << endl;
    return 0;
}
