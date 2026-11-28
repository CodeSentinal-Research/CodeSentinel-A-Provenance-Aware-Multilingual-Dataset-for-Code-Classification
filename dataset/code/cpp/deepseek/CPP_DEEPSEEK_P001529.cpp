#include <iostream>
#include <unordered_set>
#include <deque>
#include <vector>

using namespace std;

long long countSubarrays(vector<int>& nums, int k) {
    unordered_set<int> s;
    deque<int> d;
    long long res = 0;

    for (int i = 0; i < nums.size(); i++) {
        s.insert(nums[i]);
        d.push_back(nums[i]);

        if (s.size() == k) {
            while (!d.empty() && d.front() == *s.begin()) {
                d.pop_front();
                s.erase(d.front());
            }

            if (!d.empty()) {
                res += d.size();
            }
        }
    }

    return res;
}

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> nums(N);
    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }

    long long res = countSubarrays(nums, K);
    cout << res << endl;

    return 0;
}