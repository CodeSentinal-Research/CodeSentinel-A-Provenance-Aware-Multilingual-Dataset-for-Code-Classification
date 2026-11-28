Here is the C++ code for the problem:

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> consumed(N), required(N);

    for(int i = 0; i < N; i++) {
        cin >> consumed[i] >> required[i];
    }

    int minEnergy = INT_MAX;

    for(int i = 0; i < N; i++) {
        if(consumed[i] + required[i] < minEnergy) {
            minEnergy = consumed[i] + required[i];
        }
    }

    cout << minEnergy;

    return 0;
}
This code reads the number of tasks N, then reads the energy consumed and required for each task. Then it iterates through all the tasks and updates the minimum energy if a smaller energy is found. The minimum energy is printed at the end.