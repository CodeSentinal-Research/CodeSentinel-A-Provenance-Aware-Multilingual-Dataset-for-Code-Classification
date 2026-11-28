#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

int main() {
    int N, K, temp;
    cin >> N >> K;
    unordered_set<int> s;
    for(int i = 0; i < N; i++) {
        cin >> temp;
        s.insert(temp);
    }
    int count = 0;
    for(auto i = s.begin(); i != s.end(); i++) {
        if(s.find(*i + K) != s.end()) count++;
    }
    cout << count;
    return 0;
}