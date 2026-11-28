#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    string s;
    cin >> s;
    
    vector<int> lastPos(26, -1);
    for (int i = 0; i < s.length(); ++i) {
        lastPos[s[i]-'a'] = i;
    }
    
    vector<int> partitions;
    int start = 0, end = 0;
    
    for (int i = 0; i < s.length(); ++i) {
        end = max(end, lastPos[s[i]-'a']);
        if (i == end) {
            partitions.push_back(end - start + 1);
            start = i + 1;
        }
    }
    
    for (int p : partitions) {
        cout << p << " ";
    }
    cout << endl;
    
    return 0;
}
