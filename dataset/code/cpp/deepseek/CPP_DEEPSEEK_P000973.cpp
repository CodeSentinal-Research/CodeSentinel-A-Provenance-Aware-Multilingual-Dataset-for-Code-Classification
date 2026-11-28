#include <iostream>
#include <vector>

using namespace std;

double calculateProbability(int S) {
    if (S < 2 || S > 12) {
        throw invalid_argument("Invalid sum. Sum must be between 2 and 12.");
    }

    vector<int> waysToGetSum(13, 0);
    waysToGetSum[0] = 1;

    for (int i = 1; i <= 6; ++i) {
        for (int j = 12; j >= i; --j) {
            waysToGetSum[j] += waysToGetSum[j-i];
        }
    }

    return (double) waysToGetSum[S] / (6 * 6);
}

int main() {
    int S;
    cin >> S;

    try {
        double probability = calculateProbability(S);
        cout << probability << endl;
    } catch (invalid_argument& e) {
        cerr << e.what() << endl;
    }

    return 0;
}