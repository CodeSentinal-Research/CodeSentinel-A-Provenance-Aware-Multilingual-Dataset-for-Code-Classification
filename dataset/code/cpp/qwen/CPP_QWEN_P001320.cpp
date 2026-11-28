#include <iostream>
#include <string>
#include <vector>
using namespace std;

void generate(int open, int close, string current, vector<string>& result) {
    if (open == 0 && close == 0) {
        result.push_back(current);
        return;
    }
    if (open > 0) {
        generate(open - 1, close, current + "(", result);
    }
    if (close > open) {
        generate(open, close - 1, current + ")", result);
    }
}

int main() {
    int n;
    cin >> n;
    vector<string> result;
    generate(n, n, "", result);
    
    for (const string& s : result) {
        cout << s << endl;
    }
    return 0;
}
