Here is the C++ code for the problem:

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool compare(int a, int b) {
    return a > b;
}

string solve(int N, int M, int K, vector<int>& A, vector<int>& B) {
    if (N < K) {
        cout << "Invalid input" << endl;
        return "";
    }

    vector<int> C;
    for (int i = 0; i < N + M; i++) {
        if (i < N)
            C.push_back(A[i]);
        else
            C.push_back(B[i - N]);
    }

    sort(C.begin(), C.end(), compare);

    string res;
    for (int i = 0; i < N + M; i++) {
        res = to_string(C[i]) + res;
    }

    return res;
}

int main() {
    int N, M, K;
    cin >> N >> M >> K;

    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    vector<int> B(M);
    for (int i = 0; i < M; i++) {
        cin >> B[i];
    }

    string result = solve(N, M, K, A, B);
    cout << result << endl;

    return 0;
}

This code reads the input and calls the `solve` function to find the maximum number. The `solve` function first checks if the input is valid. If not, it returns an empty string. If the input is valid, it combines the two arrays into a single array C. Then, it sorts C in descending order and concatenates the digits in the string.