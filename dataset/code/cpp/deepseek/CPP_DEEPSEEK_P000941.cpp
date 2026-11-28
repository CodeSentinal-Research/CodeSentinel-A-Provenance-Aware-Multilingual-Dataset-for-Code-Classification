Here is the complete C++ code:

#include <iostream>
using namespace std;

string solve(int N, int piles[]) {
    int totalStones = 0;
    for(int i = 0; i < N; i++) {
        totalStones += piles[i];
    }

    if (totalStones % N == 0) {
        return "First";
    } else {
        return "Second";
    }
}

int main() {
    int N;
    cin >> N;
    int piles[N];
    for(int i = 0; i < N; i++) {
        cin >> piles[i];
    }

    cout << solve(N, piles);
    return 0;
}

This program takes the number of piles as input, then the number of stones in each pile. It calculates the total number of stones, and if the total number of stones is divisible by the number of piles, then it returns "First", otherwise it returns "Second".