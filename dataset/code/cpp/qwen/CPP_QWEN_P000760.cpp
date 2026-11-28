#include <iostream>
#include <vector>
using namespace std;

void generateIncreasingNumbers(int n, int start, long long current, vector<long long>& result) {
    if (n == 0) {
        result.push_back(current);
        return;
    }
    for (int i = start; i <= 9; ++i) {
        generateIncreasingNumbers(n - 1, i + 1, current * 10 + i, result);
    }
}

int main() {
    int N;
    cin >> N;
    vector<long long> result;
    generateIncreasingNumbers(N, 1, 0, result);
    
    for (long long num : result) {
        cout << num << endl;
    }
    return 0;
}
