#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> numbers(n);
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    int count = 0;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += numbers[i];
        if (sum < 0) {
            count++;
        }
    }

    cout << count << endl;

    return 0;
}