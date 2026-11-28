#include <iostream>
#include <vector>

using namespace std;

int main() {
    string bin;
    cin >> bin;

    int numSwaps = 0;
    for (int i = 0; i < bin.size() - 1; i++) {
        if (bin[i] == '1' && bin[i + 1] == '0') {
            numSwaps++;
            i++; 
        }
    }

    cout << numSwaps;

    return 0;
}