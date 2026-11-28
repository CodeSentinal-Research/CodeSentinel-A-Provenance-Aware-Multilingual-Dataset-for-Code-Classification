Here is the C++ code that will solve the problem:

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    unordered_map<int, int> freq;
    for (int i = 0; i < N; i++) {
        freq[arr[i]]++;
    }

    int count = 0;
    for (auto &p : freq) {
        int freqCount = p.second;
        int distCount = p.first;

        if (freqCount > distCount) {
            break;
        }

        if (freqCount == distCount) {
            count += (distCount * (distCount - 1)) / 2;
        } else {
            if (freqCount > 1) {
                count += (freqCount * (freqCount - 1) / 2) * distCount;
            }
        }
    }

    cout << count << endl;

    return 0;
}

This code first reads the input, and then counts the frequency of each element in the array. It then iterates through the frequency map, checking if we can form a complete subarray with all distinct elements by comparing the frequency count with the number of distinct elements. If we can't form a complete subarray with all distinct elements, it breaks the loop. If we can form a complete subarray with all distinct elements, it calculates the count. The count is then printed.