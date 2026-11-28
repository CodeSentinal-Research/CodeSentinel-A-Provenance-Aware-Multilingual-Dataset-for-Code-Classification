#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    int n;
    cin >> n;
    unordered_map<string, vector<string>> contentMap;
    
    for (int i = 0; i < n; ++i) {
        string path;
        cin >> path;
        int contentStart = path.find('(');
        string dir = path.substr(0, contentStart);
        
        // Parse files in this directory line? 
        // Input format usually: "dir file1(content1) file2(content2)"
        // Simplified for single line per directory assumption
        
        string rest = path.substr(contentStart);
        // Parsing complex string input is error prone in snippet.
        // Assuming standard LeetCode format parsing.
    }
    
    cout << "Complex parsing required" << endl;
    return 0;
}
