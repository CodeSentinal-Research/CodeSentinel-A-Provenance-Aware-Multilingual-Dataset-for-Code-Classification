#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int digitSum(int n) {
    int s = 0;
    while (n > 0) {
        s += n % 10;
        n /= 10;
    }
    return s;
}

int main() {
    int n;
    cin >> n;
    unordered_map<int, int> groupSize;
    
    for (int i = 1; i <= n; ++i) {
        groupSize[digitSum(i)]++;
    }
    
    int maxSize = 0;
    for (auto& p : groupSize) {
        maxSize = max(maxSize, p.second);
    }
    
    int count = 0;
    for (auto& p : groupSize) {
        if (p.second == maxSize) count++;
    }
    
    cout << count << endl;
    return 0;
}
