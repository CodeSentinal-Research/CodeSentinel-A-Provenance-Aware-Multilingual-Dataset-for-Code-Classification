#include <iostream>

using namespace std;

int countDerangements(int N) {
    if(N == 1) {
        return 0;
    } else if(N == 2) {
        return 1;
    } else {
        return (N - 1) * (countDerangements(N - 1) + countDerangements(N - 2));
    }
}

int main() {
    int N;
    cout << "Enter the number of objects: ";
    cin >> N;

    if(N < 1 || N > 1000) {
        cout << "Invalid input, please enter a number between 1 and 1000.";
        return 0;
    }

    cout << "Number of Derangements: " << countDerangements(N) << endl;

    return 0;
}