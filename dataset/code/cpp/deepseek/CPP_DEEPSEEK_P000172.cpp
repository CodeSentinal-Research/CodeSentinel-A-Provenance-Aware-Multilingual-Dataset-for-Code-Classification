#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> even;
    vector<int> odd;

    while (n--) {
        int num;
        cin >> num;

        if (num % 2 == 0) {
            even.push_back(num);
        } else {
            odd.push_back(num);
        }
    }

    for (int num : even) {
        cout << num << " ";
    }

    for (int num : odd) {
        cout << num << " ";
    }

    return 0;
}