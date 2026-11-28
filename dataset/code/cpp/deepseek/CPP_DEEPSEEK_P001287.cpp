Here's the code:

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    
    int sweetness[N];
    for(int i = 0; i < N; i++) {
        cin >> sweetness[i];
    }
    
    sort(sweetness, sweetness+N);
    
    int start = sweetness[K], end = sweetness[N-1];
    while(start < end) {
        int mid = (start + end) / 2;
        
        if(check(sweetness, N, mid, K+1)) {
            start = mid+1;
        } else {
            end = mid;
        }
    }
    
    cout << start-1 << "\n";
    return 0;
}

bool check(int sweetness[], int N, int mid, int K) {
    int count = 0, sum = 0;
    
    for(int i = 0; i < N; i++) {
        if(sweetness[i] < mid) continue;
        
        sum += sweetness[i];
        count++;
        
        if(count == K) break;
    }
    
    return count == K && sum >= mid;
}

This code first reads the number of sweetness values and the number of cuts. It then reads the sweetness values and sorts them. The binary search is used to find the maximum possible minimum sweetness. The `check` function checks if the given mid value can be the minimum sweetness among all pieces. If it can, then the search space is reduced to the right side (greater than mid), else the search space is reduced to the left side (less than mid). This process continues until the search space is reduced to a single element, which is the maximum possible minimum sweetness.