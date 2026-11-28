#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int w, h, n;
    cin >> w >> h >> n;
    
    vector<int> xCoords = {0, w};
    vector<int> yCoords = {0, h};
    
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        xCoords.push_back(x);
        yCoords.push_back(y);
    }
    
    sort(xCoords.begin(), xCoords.end());
    sort(yCoords.begin(), yCoords.end());
    
    int maxW = 0, maxH = 0;
    for (int i = 1; i < xCoords.size(); ++i) {
        maxW = max(maxW, xCoords[i] - xCoords[i-1]);
    }
    for (int i = 1; i < yCoords.size(); ++i) {
        maxH = max(maxH, yCoords[i] - yCoords[i-1]);
    }
    
    cout << (long long)maxW * maxH << endl;
    return 0;
}
