#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main() {
    int n; int year; cin >> n >> year;
    vector<int> years(n);
    for(int i=0; i<n; i++) cin >> years[i];
    for(int i=0; i<n; i++) if(years[i] > year) cout << i+1 << " ";
    cout << endl;
    return 0;
}
