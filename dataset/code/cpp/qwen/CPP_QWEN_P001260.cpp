#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    
    priority_queue<pair<int, char>> pq;
    if (a > 0) pq.push({a, 'a'});
    if (b > 0) pq.push({b, 'b'});
    if (c > 0) pq.push({c, 'c'});
    
    string result = "";
    
    while (!pq.empty()) {
        auto [count1, char1] = pq.top(); pq.pop();
        
        if (result.length() >= 2 && result.back() == char1 && result[result.length()-2] == char1) {
            if (pq.empty()) break;
            auto [count2, char2] = pq.top(); pq.pop();
            result += char2;
            count2--;
            if (count2 > 0) pq.push({count2, char2});
            pq.push({count1, char1});
        } else {
            result += char1;
            count1--;
            if (count1 > 0) pq.push({count1, char1});
        }
    }
    
    cout << result << endl;
    return 0;
}
