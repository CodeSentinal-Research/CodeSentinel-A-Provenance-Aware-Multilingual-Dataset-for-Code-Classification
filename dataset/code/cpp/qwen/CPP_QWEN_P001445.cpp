#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> words(n);
    for (int i = 0; i < n; ++i) cin >> words[i];
    
    unordered_map<string, int> freq;
    for (const string& w : words) freq[w]++;
    
    long long count = 0;
    for (const string& w : words) {
        count += freq[w];
    }
    
    cout << count << endl;
    return 0;
}
