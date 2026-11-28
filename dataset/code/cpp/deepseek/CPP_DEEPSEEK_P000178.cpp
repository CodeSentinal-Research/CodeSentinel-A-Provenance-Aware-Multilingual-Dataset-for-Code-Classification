Here is a C++ code snippet that satisfies your problem requirements:

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

void printArray(vector<int>& arr) {
    for (int i : arr) {
        cout << i << " ";
    }
    cout << endl;
}

bool comparator(pair<int, int>& a, pair<int, int>& b) {
    if (a.second == b.second)
        return a.first < b.first;
    return a.second > b.second;
}

int main() {
    int N;
    cin >> N;
    vector<int> arr(N);
    for (int& i : arr) {
        cin >> i;
    }
    sort(arr.begin(), arr.end());
    vector<int> count(max(arr) + 1);
    for (int i : arr) {
        count[i]++;
    }
    map<pair<int, int>, int, decltype(&comparator)> mp(comparator);
    for (int i = 0; i < arr.size(); i++) {
        mp[make_pair(arr[i], i)] = count[arr[i]];
    }
    arr.clear();
    for (auto& i : mp) {
        for (int j = 0; j < i.second; j++) {
            arr.push_back(i.first.first);
        }
    }
    printArray(arr);
    return 0;
}

This program first reads the size of the array and then the elements of the array. It then sorts the array and counts the frequency of each element. Then it constructs a map where each pair contains the element and its frequency, and sorts the map based on the frequency and then the element itself. Finally, it prints the sorted array.