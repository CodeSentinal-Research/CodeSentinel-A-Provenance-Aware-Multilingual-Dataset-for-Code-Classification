Here is the C++ code:

#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            int num;
            cin >> num;
            if(num == 0) {
                count++;
            }
        }
    }

    cout << count << endl;

    return 0;
}

This code will take an input N, then it will iterate through N rows. For each row, it will take another N inputs and check if the current input is 0. If it is, it will increment a global count variable. Finally, it will print out the count of zeros.