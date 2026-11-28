#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    unordered_map<int, int> count;
    for (int i = 0; i < N; i++) {
        int num1, num2;
        cin >> num1 >> num2;
        count[num1]++;
        count[num2]--;
    }

    int sum = 0;
    for (auto &p : count) {
        sum += p.second;
        cout << sum << endl;
    }

    return 0;
}