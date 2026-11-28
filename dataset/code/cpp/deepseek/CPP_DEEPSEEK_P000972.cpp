#include <iostream>
using namespace std;

double probability(int N, int K) {
    double probability = 1.0;
    for (int i = 0; i < K; i++) {
        probability *= (N - i) / (double)(N - i + 1);
    }
    probability *= (K + 1) / (double)(K + 1);
    return probability;
}

int main() {
    int N, K;
    cout << "Enter N and K: ";
    cin >> N >> K;

    if (N < 1 || N > 1000 || K < 0 || K > N) {
        cout << "Invalid input" << endl;
        return 0;
    }

    cout << "Probability: " << probability(N, K) << endl;

    return 0;
}