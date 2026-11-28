#include <iostream>
#include <string>
#include <cmath>
using namespace std;

void generateGrayCode(int n, string current) {
    if (n == 0) {
        cout << current << endl;
        return;
    }
    generateGrayCode(n - 1, "0" + current);
    // For the second half, we reverse the order of the previous bits effectively by logic, 
    // but standard recursive construction:
    // G(n) = 0G(n-1) followed by 1G(n-1) reversed.
    // Implementing reversal recursively is complex. 
    // Alternative: Use formula G(i) = i ^ (i >> 1).
    // But problem asks for recursion.
    // Let's stick to simple bit manipulation recursion if possible or just iterate using formula if "Recursion" category allows helper.
    // Actually, standard recursive definition:
    // List L(n-1). Reverse L(n-1) -> R. Prefix 0 to L, 1 to R. Concatenate.
    
    // Since printing in order is required, let's use the iterative formula inside a recursive wrapper or just print directly.
    // To strictly follow "Recursion", let's generate the list.
}

// Better approach for Recursion category:
void grayCodeRecursive(int n, vector<string>& codes) {
    if (n == 1) {
        codes.push_back("0");
        codes.push_back("1");
        return;
    }
    vector<string> prev;
    grayCodeRecursive(n - 1, prev);
    for (const string& s : prev) codes.push_back("0" + s);
    for (int i = prev.size() - 1; i >= 0; --i) codes.push_back("1" + prev[i]);
}

int main() {
    int n;
    cin >> n;
    if (n == 0) return 0;
    vector<string> codes;
    grayCodeRecursive(n, codes);
    for (const string& code : codes) {
        cout << code << endl;
    }
    return 0;
}
