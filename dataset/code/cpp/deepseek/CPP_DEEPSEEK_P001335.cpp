#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool canFormSquare(vector<int>& matchsticks) {
    int sum = 0;
    for (int length : matchsticks) {
        sum += length;
    }
    
    if (sum % 4 != 0) {
        return false;
    }
    
    sort(matchsticks.begin(), matchsticks.end(), greater<int>());
    
    int edge1 = matchsticks[0];
    int edge2 = 0;
    int edge3 = 0;
    int edge4 = 0;
    
    for (int i = 1; i < 4; i++) {
        edge2 += matchsticks[i];
        edge3 += matchsticks[i];
        edge4 += matchsticks[i];
    }
    
    if (edge1 > edge2 && edge1 > edge3 && edge1 > edge4) {
        edge2 += edge1;
        edge3 += edge1;
        edge4 += edge1;
    } else if (edge2 > edge1 && edge2 > edge3 && edge2 > edge4) {
        edge1 += edge2;
        edge3 += edge2;
        edge4 += edge2;
    } else if (edge3 > edge1 && edge3 > edge2 && edge3 > edge4) {
        edge1 += edge3;
        edge2 += edge3;
        edge4 += edge3;
    } else {
        edge1 += edge4;
        edge2 += edge4;
        edge3 += edge4;
    }
    
    if (edge1 == edge2 && edge1 == edge3 && edge1 == edge4) {
        return true;
    }
    
    return false;
}

int main() {
    int n;
    cin >> n;
    
    vector<int> matchsticks(n);
    for (int i = 0; i < n; i++) {
        cin >> matchsticks[i];
    }
    
    if (canFormSquare(matchsticks)) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    
    return 0;
}
This code first calculates the total sum of the lengths of the matchsticks. If the sum is not a multiple of 4, it returns false. Then it sorts the matchsticks in descending order, and calculates the sum of the first 3 edges (the longest and the second longest). It then checks if any of the remaining edges can add up to the sum of the first 3 edges, and if so, does so. If none of the edges can add up to the sum of the first 3 edges, it returns false. If all edges can add up to the sum of the first 3 edges, it returns true.