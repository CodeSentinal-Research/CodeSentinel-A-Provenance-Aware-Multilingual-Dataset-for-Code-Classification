#include <iostream>
using namespace std;

int main() {
    int n, target, count = 0;
    cin >> n >> target;

    for(int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        if(temp == target) {
            count++;
        }
    }

    cout << count << endl;

    return 0;
}