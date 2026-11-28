#include <iostream>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    
    int flips = 0;
    for (int i = 0; i < 32; ++i) {
        int bitA = (a >> i) & 1;
        int bitB = (b >> i) & 1;
        int bitC = (c >> i) & 1;
        
        int orAB = bitA | bitB;
        if (orAB != bitC) {
            if (bitC == 1) flips++; // Need to set one of A or B to 1
            else {
                if (bitA) flips++;
                if (bitB) flips++;
            }
        }
    }
    cout << flips << endl;
    return 0;
}
