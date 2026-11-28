Here is the C++ code to solve the problem:

#include <iostream>
using namespace std;

int main() {
    int N, K;
    cout << "Enter the number of balls: ";
    cin >> N;
    cout << "Enter the number of boxes: ";
    cin >> K;

    if (K > N) {
        cout << "It is not possible to distribute N balls into K boxes" << endl;
        return 0;
    }

    if (N == K) {
        cout << "The number of valid distributions is 1" << endl;
        return 0;
    }

    long long valid_distributions = (K-1) != 0 ? (K-1) : 1;
    for(int i=K; i>=1; --i) {
        valid_distributions *= i;
        valid_distributions /= (N-K+i);
    }

    cout << "The number of valid distributions is " << valid_distributions << endl;

    return 0;
}

This program reads the number of balls and boxes from the standard input. It then calculates the number of valid distributions based on the problem statement. The calculation is based on the formula for combinations and permutations in probability theory, which states that the number of valid distributions is the product of the (K-1)! / ((N-K)! K!) for (K-1) and (N-K+i) for i in (K, N).