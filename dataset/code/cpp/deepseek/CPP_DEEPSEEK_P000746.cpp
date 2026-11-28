Here is the C++ code for the Josephus problem using recursion:

#include <iostream>

using namespace std;

int josephus(int N, int K) {
    if (N == 1) {
        return 1;
    } else {
        return (josephus(N - 1, K) + K - 1) % N + 1;
    }
}

int main() {
    int N, K;
    cout << "Enter the number of people and the interval: ";
    cin >> N >> K;
    cout << "The survivor is at position: " << josephus(N, K) << endl;
    return 0;
}
This program first takes the number of people and the interval (K) as input. Then it calls the `josephus` function with the given inputs, and prints the position of the survivor.