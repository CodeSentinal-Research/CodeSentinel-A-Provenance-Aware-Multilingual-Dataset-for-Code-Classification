#include <iostream>
#include <unordered_map>
#include <cmath>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    unordered_map<int, int> count;
    count[0] = 1;

    int sum = 0, ans = 0;
    for(int i = 0; i < N; i++) {
        int a;
        cin >> a;
        sum += a;
        sum %= K;

        if(sum < 0)
            sum += K;

        ans += count[sum];

        count[sum]++;
    }

    cout << ans;
    return 0;
}