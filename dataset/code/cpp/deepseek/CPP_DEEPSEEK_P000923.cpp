#include <iostream>
using namespace std;

int countNumbersWithUniqueDigits(int N) {
    if (N <= 0 || N > 8) {
        cout << "Invalid input" << endl;
        return -1;
    }

    int count = 0;
    for (int i = 1; i <= N; i++) {
        string num = to_string(i);
        set<char> uniqueDigits(num.begin(), num.end());
        if (uniqueDigits.size() == 10) {
            count++;
        }
    }

    return count;
}

int main() {
    int N;
    cout << "Enter a positive integer N (0 <= N <= 8): ";
    cin >> N;

    int result = countNumbersWithUniqueDigits(N);
    if (result != -1) {
        cout << "Count of numbers with unique digits: " << result << endl;
    }

    return 0;
}