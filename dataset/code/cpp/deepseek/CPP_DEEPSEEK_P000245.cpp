Here is the code:

#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= i; j++) {
            int elem;
            cin >> elem;
            if(j != i) {
                cout << elem << " ";
            } else {
                cout << elem << endl;
            }
        }
    }

    return 0;
}
This program reads an integer `n`, then reads `n` lines of integers. For each line, it prints the lower triangular part of the matrix. If the current row is not the last one, it prints the element followed by a space, otherwise, it just prints the element followed by a newline.