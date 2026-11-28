#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    int operations = 0;
    while(true) {
        bool flag = false;
        for(int i=0; i<n; i++) {
            if(arr[i] > 0) {
                arr[i] -= min(arr[i], arr[0]);
                flag = true;
            }
        }
        if(!flag) break;
        operations++;
    }
    cout << operations;
    return 0;
}