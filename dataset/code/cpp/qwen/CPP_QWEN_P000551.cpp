#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main() {
    int N;
    cin >> N;
    queue<string> q;
    q.push("1");
    for (int i = 0; i < N; i++) {
        string curr = q.front(); q.pop();
        cout << curr << " ";
        q.push(curr + "0");
        q.push(curr + "1");
    }
    cout << endl;
    return 0;
}
