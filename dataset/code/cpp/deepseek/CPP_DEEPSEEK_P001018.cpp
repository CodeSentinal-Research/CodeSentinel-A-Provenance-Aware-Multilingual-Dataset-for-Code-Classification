#include <iostream>
#include <queue>
#include <map>
using namespace std;

void reorganizeString(string str) {
    map<char, int> freq;
    for (char c : str) freq[c]++;

    priority_queue<pair<int, char>> maxHeap;
    for (auto p : freq) maxHeap.push({p.second, p.first});

    string result = "";
    while (maxHeap.size() > 1) {
        pair<int, char> first = maxHeap.top(); maxHeap.pop();
        pair<int, char> second = maxHeap.top(); maxHeap.pop();
        result += first.second; result += second.second;
        if (--first.first > 0) maxHeap.push(first);
        if (--second.first > 0) maxHeap.push(second);
    }
    if (maxHeap.empty() || maxHeap.top().first > 1) result += maxHeap.top().second;
    else cout << "IMPOSSIBLE";
}

int main() {
    string str;
    cin >> str;
    reorganizeString(str);
    return 0;
}