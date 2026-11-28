#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> ratings(n);
    for(int i = 0; i < n; i++) {
        cin >> ratings[i];
    }
    vector<int> candies(n, 1);
    for(int i = 1; i < n; i++) {
        if(ratings[i] > ratings[i-1]) {
            candies[i] = candies[i-1] + 1;
        }
    }
    for(int i = n - 2; i >= 0; i--) {
        if(ratings[i] > ratings[i+1]) {
            candies[i] = max(candies[i], candies[i+1] + 1);
        }
    }
    int total_candies = 0;
    for(int candy : candies) {
        total_candies += candy;
    }
    cout << total_candies << endl;
    return 0;
}