Here is the code:

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int key;
    cin >> key;

    unordered_map<int, int> freq;
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] == key) {
            freq[arr[i + 1]]++;
        }
    }

    int maxFreq = 0, res;
    for (auto &i : freq) {
        if (i.second > maxFreq) {
            maxFreq = i.second;
            res = i.first;
        }
    }
    cout << res;
    return 0;
}

This program reads the size of the array, array elements, and the key from the standard input. It then creates an unordered_map to store the frequency of each number, and then iterates through the array to fill the map. Finally, it finds the most frequent number after the key and prints it.