#include <iostream>
using namespace std;

int kthGrammar(int N, int K) {
    if (N == 1) return 0;
    int M = K % 2 == 0 ? K / 2 : K / 2 - 1; 
    return kthGrammar(N - 1, M) == 0 ? 1 : 0; 
}

int main() {
    int N, K;
    cout << "Enter N and K: ";
    cin >> N >> K;
    cout << "Kth symbol: " << kthGrammar(N, K) << endl;
    return 0;
}

This code defines a function `kthGrammar(N, K)` that takes two integers as input and calculates the K-th symbol in the N-th row of the grammar. The function is recursive, and it calls itself with the previous N and M divided by 2 if M is even, or divided by 2 minus one if M is odd. This process continues until it reaches the base case where N is 1, at which point it returns 0. The main function then handles the input and calls the `kthGrammar` function to output the K-th symbol.