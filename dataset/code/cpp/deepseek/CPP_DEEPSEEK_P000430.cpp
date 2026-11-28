Here is the complete C++ code for your problem:

#include <iostream>
using namespace std;

int main() {
    int N, target;
    cin >> N >> target;

    int arr[N];
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int lastIndex = -1;
    for (int i = N - 1; i >= 0; i--) {
        if (arr[i] == target) {
            lastIndex = i;
            break;
        }
    }

    cout << lastIndex << endl;

    return 0;
}

This code first reads the number of elements N and the target value. Then it reads the array of N elements. It then uses a for loop to go from the end of the array to the beginning, and if it finds a match with the target, it updates the lastIndex and breaks the loop. Finally, it prints the lastIndex.