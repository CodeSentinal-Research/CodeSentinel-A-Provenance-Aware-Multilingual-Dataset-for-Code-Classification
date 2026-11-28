#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main() {
    int n; int date; cin >> n >> date;
    vector<int> dates(n);
    for(int i=0; i<n; i++) cin >> dates[i];
    for(int i=0; i<n; i++) if(dates[i] < date) cout << i+1 << " ";
    cout << endl;
    return 0;
}
