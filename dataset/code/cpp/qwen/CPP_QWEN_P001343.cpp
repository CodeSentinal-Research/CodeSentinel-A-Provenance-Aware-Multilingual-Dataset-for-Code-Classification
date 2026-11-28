#include <iostream>
#include <vector>
using namespace std;

void generateGrayCode(int n, vector<string>& codes) {
    if (n == 1) {
        codes.push_back("0");
        codes.push_back("1");
        return;
    }
    vector<string> prev;
    generateGrayCode(n - 1, prev);
    for (const string& s : prev) codes.push_back("0" + s);
    for (int i = prev.size() - 1; i >= 0; --i) codes.push_back("1" + prev[i]);
}

int main() {
    int n;
    cin >> n;
    vector<string> codes;
    generateGrayCode(n, codes);
    
    for (const string& code : codes) {
        cout << code << endl;
    }
    return 0;
}
