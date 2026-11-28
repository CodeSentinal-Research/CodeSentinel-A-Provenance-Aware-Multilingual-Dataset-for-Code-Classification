#include <iostream>
#include <vector>

using namespace std;

vector<int> countPeople(int n, vector<int> heights) {
    vector<int> count(n, 0);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (heights[j] > heights[i]) {
                count[i]++;
            }
        }
    }
    return count;
}

int main() {
    int n;
    cin >> n;
    vector<int> heights(n);
    for (int i = 0; i < n; i++) {
        cin >> heights[i];
    }
    vector<int> count = countPeople(n, heights);
    for (int i = 0; i < n; i++) {
        cout << count[i] << " ";
    }
    return 0;
}
This code first reads the number of people and their heights, then calls the countPeople function with the heights and prints the number of people visible to each person to their right.