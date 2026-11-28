#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;

int find(int x) {
    if (parent[x] == x)
        return x;
    else
        return parent[x] = find(parent[x]);
}

void merge(int x, int y) {
    x = find(x);
    y = find(y);
    if (x != y)
        parent[y] = x;
}

int main() {
    int N, M;
    cin >> N >> M;

    parent.resize(N + 1);
    for (int i = 1; i <= N; i++)
        parent[i] = i;

    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        merge(x, y);
    }

    int connected_components = 0;
    for (int i = 1; i <= N; i++)
        if (parent[i] == i)
            connected_components++;

    cout << connected_components << endl;

    return 0;
}
This C++ code will take in the number of nodes (N) and edges (M) as inputs. It initializes a vector parent with size N+1 and sets all elements as the parent of themselves.

Then it reads in edges and calls the merge function to merge two nodes into a connected component if they are not already connected.

Finally, it counts the connected components by iterating over the parent vector and checking if each node is its parent. If it is, then the node is in a connected component. The connected component count is stored in the variable connected_components and printed out.