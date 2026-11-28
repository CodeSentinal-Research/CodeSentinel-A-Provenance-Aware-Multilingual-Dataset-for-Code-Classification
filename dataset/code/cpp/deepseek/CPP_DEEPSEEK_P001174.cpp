#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<vector<int>> triangle(N, vector<int>(N));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j <= i; ++j) {
            cin >> triangle[i][j];
        }
    }

    for (int i = N - 2; i >= 0; --i) {
        for (int j = 0; j <= i; ++j) {
            triangle[i][j] += min(triangle[i+1][j], triangle[i+1][j+1]);
        }
    }

    cout << triangle[0][0] << endl;

    return 0;
}
This code reads an integer N followed by a triangle of integers. It then calculates the minimum path sum from the top to the bottom of the triangle, at each step, moving only to one of the two adjacent numbers in the next row. The code finally prints the minimum path sum.