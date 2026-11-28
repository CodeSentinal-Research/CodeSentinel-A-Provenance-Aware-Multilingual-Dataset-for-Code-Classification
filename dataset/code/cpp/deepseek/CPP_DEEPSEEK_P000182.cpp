#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    unordered_map<int, int> freq;
    for (int i = 0; i < n; i++) {
        freq[arr[i]]++;
    }

    int max_freq = 0;
    int most_frequent = -1;
    for (auto& p : freq) {
        if (p.second > max_freq) {
            max_freq = p.second;
            most_frequent = p.first;
        }
    }

    cout << most_frequent << "\n";

    return 0;
}
This program first reads the size of the array from the input and then the elements of the array itself. It then counts the frequency of each element and keeps track of the element with the highest frequency. The frequency is stored in the `max_freq` variable, and the most frequent element is stored in the `most_frequent` variable.