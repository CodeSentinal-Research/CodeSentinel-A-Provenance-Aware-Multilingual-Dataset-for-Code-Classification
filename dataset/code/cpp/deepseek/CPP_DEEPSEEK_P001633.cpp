Here is the code:

#include <iostream>
using namespace std;

int main() {
    int N, M, K;
    cin >> N >> M >> K;
    int matrix[N][M];
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> matrix[i][j];
        }
    }
    int max_area = 0;
    for(int left = 0; left < N; left++) {
        for(int right = left; right < N; right++) {
            int sum = 0;
            for(int i = left; i <= right; i++) {
                sum += matrix[i][0];
                if(sum > max_area && sum <= K) {
                    max_area = sum;
                }
            }
            for(int i = right+1; i < N; i++) {
                sum -= matrix[i][0];
                if(sum > max_area && sum <= K) {
                    max_area = sum;
                }
            }
        }
    }
    cout << max_area << endl;
    return 0;
}
This code takes an NxM matrix and a K as input, calculates the sum for each possible submatrix and keeps track of the maximum sum that is not exceeding K. The time complexity is O(N^3) due to the three nested loops.