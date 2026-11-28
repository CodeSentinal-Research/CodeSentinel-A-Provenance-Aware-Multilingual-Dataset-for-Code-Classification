#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int count = 0;
    int maxCount = 0;

    for(int i = 0; i < n; i++) {
        int num;
        cin >> num;

        if(num == 0) {
            count++;
        } else {
            if(count > maxCount) {
                maxCount = count;
            }
            count = 0;
        }
    }

    if(count > maxCount) {
        maxCount = count;
    }

    cout << maxCount << endl;

    return 0;
}