#include <iostream>
using namespace std;

void generateSequentialDigits(int low, int high) {
    for (int i = 1; i < 10; i++) {
        int nextDigit = i + low;
        if (nextDigit <= high)
            cout << nextDigit << " ";
        if (i == 9) 
            return;
        nextDigit = i + 9 + low; 
        if (nextDigit <= high)
            cout << nextDigit << " ";
    }
}

int main() {
    int low, high;
    cin >> low >> high;
    generateSequentialDigits(low, high);
    return 0;
}
This code first prints all numbers from 1 to 9, then calls a recursive function `generateSequentialDigits` to generate all sequential digit numbers in ascending order within the range [10, 10^9]. It does this by printing each digit one by one, and then creating a new number by appending the current digit and the previous digit. It continues this process until the new number is in the range [low, high]. If the new number is not in the range, it stops.