#include <iostream>
#include <vector>
#include <string>
using namespace std;
int minOperations(vector<string>& logs) {
    int depth = 0;
    for(string log : logs) {
        if(log == "../") { if(depth > 0) depth--; }
        else if(log != "./") { depth++; }
    }
    return depth;
}
int main() {
    int n; cin >> n;
    vector<string> logs(n);
    for(int i=0; i<n; i++) cin >> logs[i];
    cout << minOperations(logs) << endl;
    return 0;
}
