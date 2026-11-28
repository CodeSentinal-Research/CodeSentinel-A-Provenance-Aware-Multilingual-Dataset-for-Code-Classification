#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int M, N;
    cin >> M >> N;

    vector<int> array1(M);
    for (int i = 0; i < M; i++) {
        cin >> array1[i];
    }

    vector<int> array2(N);
    for (int i = 0; i < N; i++) {
        cin >> array2[i];
    }

    sort(array1.begin(), array1.end());

    vector<int> result;
    for (int i = 0; i < M; i++) {
        if (find(array2.begin(), array2.end(), array1[i]) != array2.end()) {
            result.push_back(array1[i]);
        } else {
            result.push_back(array1[i]);
        }
    }

    for (int i = 0; i < N; i++) {
        if (find(array1.begin(), array1.end(), array2[i]) == array1.end()) {
            result.push_back(array2[i]);
        }
    }

    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}