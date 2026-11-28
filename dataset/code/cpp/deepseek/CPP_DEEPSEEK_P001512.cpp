#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
    int N, Goal;
    cin >> N >> Goal;

    vector<int> nums(N);
    for(int i = 0; i < N; i++) {
        cin >> nums[i];
    }

    int count = 0;
    unordered_map<int, int> map;
    int sum = 0;
    for(int i = 0; i < N; i++) {
        sum += nums[i];
        if(sum == Goal) {
            count++;
            sum = 0;
            continue;
        }
        if(map.find(sum - Goal) != map.end()) {
            count += map[sum - Goal];
        }
        map[sum]++;
    }

    cout << count << endl;

    return 0;
}