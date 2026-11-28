#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> counts;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> freqs;
    for (int num : nums) {
        ++counts[num];
    }
    for (auto& p : counts) {
        freqs.push(p);
   
        if (freqs.size() > k) {
            freqs.pop();
        }
    }

    vector<int> result;
    while (!freqs.empty()) {
        result.push_back(freqs.top().first);
        freqs.pop();
    }

    return result;
}

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> nums(N);
    for (int i = 0; i < N; ++i) {
        cin >> nums[i];
    }
    vector<int> result = topKFrequent(nums, K);
    for (int num : result) {
        cout << num << ' ';
    }
    return 0;
}
This C++ solution utilizes the `unordered_map` to count the frequency of each number in the input array, and `priority_queue` to handle the frequency pairs. The frequency pair contains a number and its frequency, and `priority_queue` automatically sorts the pairs by the first element in ascending order. The `topKFrequent` function then pops the top pair and adds the number to the result array, until the size of the priority queue is less than the input K. The result is then printed out.