#include <iostream>
using namespace std;

const int MAX = 1e6 + 5;
int phi[MAX]; 

void computePhis(int n) {
    for(int i = 1; i <= n; i++) {
        phi[i] = i;
    }

    for(int p = 2; p * p <= n; p++) {
        if(phi[p] == p) {
            for(int i = p * p; i <= n; i += p) {
                phi[i] = phi[i] / p * (p - 1);
            }
        }
    }

    for(int i = 2; i <= n; i++) {
        phi[i] += phi[i - 1];
    }
}

int main() {
    int n;
    cin >> n;

    if(n < 1 || n > 1e6) {
        cout << "Invalid input.";
        return 0;
    }

    computePhis(n);

    for(int i = 1; i <= n; i++) {
        cout << phi[i] << " ";
    }

    return 0;
}