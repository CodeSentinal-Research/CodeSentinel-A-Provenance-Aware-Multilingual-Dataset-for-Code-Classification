Here is the code for the Tribonacci Sequence problem.

#include <iostream>
using namespace std;

int main() {
    int N;
    cout << "Enter the value of N: ";
    cin >> N;

    if(N >= 0 && N <= 100000){
        int *Tribonacci = new int[N+1];
        Tribonacci[0] = 0;
        Tribonacci[1] = 1;
        Tribonacci[2] = 1;

        for(int i=3; i<=N; i++) {
            Tribonacci[i] = Tribonacci[i-1] + Tribonacci[i-2] + Tribonacci[i-3];
        }

        cout << "The " << N << "th Tribonacci number is " << Tribonacci[N] << endl;

        delete[] Tribonacci;
    }
    else {
        cout << "Invalid input" << endl;
    }

    return 0;
}

This program will take an input `N` and calculate the `N`th Tribonacci number. The sequence is stored in an array `Tribonacci` and the complexity is `O(N)`.