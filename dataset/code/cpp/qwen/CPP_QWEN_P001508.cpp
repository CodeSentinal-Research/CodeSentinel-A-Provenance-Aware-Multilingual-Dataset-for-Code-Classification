#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> fruits(n);
    for (int i = 0; i < n; ++i) cin >> fruits[i];
    
    unordered_map<int, int> basket;
    int maxFruits = 0;
    int left = 0;
    
    for (int right = 0; right < n; ++right) {
        basket[fruits[right]]++;
        
        while (basket.size() > 2) {
            basket[fruits[left]]--;
            if (basket[fruits[left]] == 0) {
                basket.erase(fruits[left]);
            }
            left++;
        }
        
        maxFruits = max(maxFruits, right - left + 1);
    }
    
    cout << maxFruits << endl;
    return 0;
}
