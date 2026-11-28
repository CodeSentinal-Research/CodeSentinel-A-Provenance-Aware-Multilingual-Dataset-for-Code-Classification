#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findPlatforms(vector<int> &arrival, vector<int> &departure, int n) {
    sort(arrival.begin(), arrival.end());
    sort(departure.begin(), departure.end());
    
    int platforms = 1;
    
    int i = 1;
    for (int j = 0; j < n; j++) {
        while (departure[j] > arrival[i]) {
            platforms++;
            i++;
        }
        platforms--;
    }
    
    return platforms;
}

int main() {
    int n;
    cin >> n;
    
    vector<int> arrival(n), departure(n);
    
    for (int i = 0; i < n; i++) {
        cin >> arrival[i] >> departure[i];
    }
    
    cout << findPlatforms(arrival, departure, n) << "\n";
    
    return 0;
}