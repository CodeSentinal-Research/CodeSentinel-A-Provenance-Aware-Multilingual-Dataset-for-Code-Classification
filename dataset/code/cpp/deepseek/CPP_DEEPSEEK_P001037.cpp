#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
    if(a.first == b.first)
        return a.second < b.second;
    return a.first < b.first;
}

int taskScheduling(vector<char> &tasks, int k) {
    vector<pair<int, int>> freq(26);
    for(char c : tasks) {
        freq[c - 'A'].first++;
        freq[c - 'A'].second = c - 'A';
    }
    sort(freq.begin(), freq.end(), cmp);
    
    int ans = tasks.size();
    vector<int> pos(26);
    for(int i = 0; i < tasks.size(); i++) {
        int taskId = tasks[i] - 'A';
        if(freq[taskId].first > 0) {
            freq[taskId].first--;
            pos[taskId] = i;
        }
        else {
            for(int j = 0; j < 26; j++) {
                if(freq[j].first > 0 && pos[j] >= i - k) {
                    freq[j].first--;
                    pos[j] = i;
                    break;
                }
            }
        }
        int maxf = 0;
        for(int j = 0; j < 26; j++) {
            if(maxf < freq[j].first)
                maxf = freq[j].first;
        }
        if(maxf > 0)
            ans += k - (i - pos[maxf]);
    }
    return ans;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<char> tasks(n);
    for(int i = 0; i < n; i++) {
        cin >> tasks[i];
    }
    cout << taskScheduling(tasks, k) << endl;
    return 0;
}