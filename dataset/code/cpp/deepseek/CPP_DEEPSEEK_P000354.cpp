#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int x;
    cin >> x;

    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            count++;
        }
    }

    cout << count << endl;

    return 0;
}
This program reads the size of the array and the array itself, as well as the element to count, and then counts the number of occurrences of the given element in the array. It then prints the count.