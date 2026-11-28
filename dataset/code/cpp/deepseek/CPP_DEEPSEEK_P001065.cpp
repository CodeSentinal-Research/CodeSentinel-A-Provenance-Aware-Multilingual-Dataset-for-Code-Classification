#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    int total_edges = 0;
    for (int i = 0; i < N; i++) {
        int num_neighbors;
        cin >> num_neighbors;
        total_edges += num_neighbors;
    }
    cout << total_edges << endl;
    return 0;
}