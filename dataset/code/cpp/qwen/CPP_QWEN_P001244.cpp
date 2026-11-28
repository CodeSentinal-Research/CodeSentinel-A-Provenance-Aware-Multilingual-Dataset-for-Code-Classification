#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>
using namespace std;

int main() {
    string s;
    cin >> s;
    
    unordered_map<char, int> freq;
    for (char c : s) freq[c]++;
    
    priority_queue<pair<int, char>> pq;
    for (auto& p : freq) {
        pq.push({p.second, p.first});
    }
    
    string result = "";
    pair<int, char> prev = {-1, '#'};
    
    while (!pq.empty()) {
        auto [count, c] = pq.top();
        pq.pop();
        
        result += c;
        count--;
        
        if (prev.first > 0) {
            pq.push(prev);
        }
        
        prev = {count, c};
    }
    
    if (result.length() != s.length()) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        cout << result << endl;
    }
    
    return 0;
}
