#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> count(1000000, 0);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        count[x]++;
    }
    int minRabbits = 0;
    for (int i = 0; i < 1000000; i++) {
        minRabbits += count[i];
        int size = i + 1;
        while (minRabbits >= size) {
            minRabbits -= size;
            size++;
        }
    }
    cout << minRabbits << endl;
    return 0;
}