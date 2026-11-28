#include <iostream>
using namespace std;

int main() {
    int size, N;
    cin >> size >> N;

    int flowerbed[size];
    for(int i = 0; i < size; i++) {
        cin >> flowerbed[i];
    }

    for(int i = 0; i < size; i++) {
        if(flowerbed[i] == 0 && (i == 0 || i == size - 1) && N > 0) {
            flowerbed[i] = 1;
            N--;
        }
    }

    if(N > 0) {
        cout << "No";
    } else {
        cout << "Yes";
    }

    return 0;
}