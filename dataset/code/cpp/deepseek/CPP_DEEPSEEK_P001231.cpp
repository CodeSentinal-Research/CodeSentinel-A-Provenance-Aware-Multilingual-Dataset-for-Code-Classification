Sure, here is the code:

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> children(N);
    for(int& child : children) {
        cin >> child;
    }

    vector<int> cookies(M);
    for(int& cookie : cookies) {
        cin >> cookie;
    }

    sort(children.begin(), children.end());
    sort(cookies.begin(), cookies.end());

    int satisfiedChildren = 0;
    int i = 0, j = 0;
    while(i < N && j < M) {
        if(children[i] >= cookies[j]) {
            satisfiedChildren++;
            i++;
        }
        j++;
    }

    cout << satisfiedChildren << endl;

    return 0;
}

This code first reads the number of children and cookies. Then it sorts both lists. It then iterates over both lists simultaneously. If a child's requirement is greater than or equal to a cookie's size, the child is satisfied and the child's requirement is increased. The iterators are incremented in the same order. The maximum number of satisfied children is stored in the `satisfiedChildren` variable. The final answer is printed to the console.