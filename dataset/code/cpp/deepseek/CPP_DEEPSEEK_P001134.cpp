#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int* arr = new int[n];
        for(int i=0; i<n; i++) {
            cin >> arr[i];
        }
        int incl = 0, excl = 0;
        incl = excl + arr[0];
        excl = incl > excl ? incl : excl;
        for(int i=1; i<n; i++) {
            int new_excl = incl > excl ? incl : excl;
            incl = excl + arr[i];
            excl = new_excl;
        }
        int res = incl > excl ? incl : excl;
        cout << res << endl;
        delete [] arr;
    }
    return 0;
}