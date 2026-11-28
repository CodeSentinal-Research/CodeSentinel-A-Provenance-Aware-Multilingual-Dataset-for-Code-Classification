#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main() {
    int n; string suffix; cin >> n >> suffix;
    vector<string> products(n);
    for(int i=0; i<n; i++) cin >> products[i];
    for(int i=0; i<n; i++) {
        if(products[i].size() >= suffix.size() && products[i].compare(n - suffix.size(), suffix.size(), suffix) == 0)
            cout << i+1 << " ";
    }
    cout << endl;
    return 0;
}
