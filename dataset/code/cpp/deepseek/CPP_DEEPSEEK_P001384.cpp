#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n + 1, 0);
    for(int i = 0; i < n; i++) {
        int num;
        cin >> num;
        arr[num]++;
    }
    for(int i = 1; i <= n; i++) {
        if(arr[i] > 1) {
            cout << i << " ";
        }
    }
    return 0;
}