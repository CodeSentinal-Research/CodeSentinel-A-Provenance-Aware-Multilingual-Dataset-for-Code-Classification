Here is the C++ code to solve the given problem.

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> in_degrees(N, 0);

    for(int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        in_degrees[b]++;
    }

    int count = 0;
    for(int i = 0; i < N; i++) {
        if(in_degrees[i] == 0) {
            count++;
        }
    }

    cout << count << endl;

    return 0;
}

This program first reads the number of vertices (N) and edges (M) from the input. It then reads the edges and updates the in-degree of each vertex. After that, it counts the number of vertices that have an in-degree of zero and prints the count.