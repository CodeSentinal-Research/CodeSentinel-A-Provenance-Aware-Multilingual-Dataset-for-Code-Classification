#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <climits>
using namespace std;

int main() {
    int n, m;
    cin >> n;
    vector<string> list1(n);
    for (int i = 0; i < n; ++i) cin >> list1[i];
    
    cin >> m;
    vector<string> list2(m);
    for (int i = 0; i < m; ++i) cin >> list2[i];
    
    unordered_map<string, int> indexMap;
    for (int i = 0; i < n; ++i) indexMap[list1[i]] = i;
    
    int minSum = INT_MAX;
    vector<string> result;
    
    for (int i = 0; i < m; ++i) {
        if (indexMap.find(list2[i]) != indexMap.end()) {
            int sum = i + indexMap[list2[i]];
            if (sum < minSum) {
                minSum = sum;
                result.clear();
                result.push_back(list2[i]);
            } else if (sum == minSum) {
                result.push_back(list2[i]);
            }
        }
    }
    
    for (const string& s : result) cout << s << endl;
    return 0;
}
