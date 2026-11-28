#include <iostream>
#include <string>
#include <vector>
using namespace std;

void generateBinaryStrings(int n, string current, vector<string>& result) {
    if (n == 0) {
        result.push_back(current);
        return;
    }
    generateBinaryStrings(n - 1, current + "0", result);
    if (current.empty() || current.back() != '1') {
        generateBinaryStrings(n - 1, current + "1", result);
    }
}

int main() {
    int n;
    cin >> n;
    vector<string> result;
    generateBinaryStrings(n, "", result);
    
    for (const string& s : result) {
        cout << s << endl;
    }
    return 0;
}
