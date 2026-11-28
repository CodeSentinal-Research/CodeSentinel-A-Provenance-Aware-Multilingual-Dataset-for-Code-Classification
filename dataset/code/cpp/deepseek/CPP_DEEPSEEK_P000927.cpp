#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

string convertBase(string num, int base) {
    int size = num.size();
    int carry = 0;
    for (int i = 0; i < size; i++) {
        int digit = num[i] - '0';
        int temp = digit + carry;
        if (base <= 10)
            temp += base;
        else if (base == 11)
            temp += (digit < 5 ? 5 : 9);
        else if (base == 12)
            temp += (digit < 6 ? 6 : 9);
        else if (base == 13)
            temp += (digit < 7 ? 7 : 9);
        else if (base == 14)
            temp += (digit < 8 ? 8 : 9);
        else if (base == 15)
            temp += (digit < 9 ? 9 : 4);
        else if (base == 16)
            temp += (digit < 10 ? 10 : 5);
        else if (base == 17)
            temp += (digit < 11 ? 11 : 6);
        else if (base == 18)
            temp += (digit < 12 ? 12 : 7);
        else if (base == 19)
            temp += (digit < 13 ? 13 : 8);
        else if (base == 20)
            temp += (digit < 14 ? 14 : 9);
        else if (base == 21)
            temp += (digit < 15 ? 15 : 10);
        else if (base == 22)
            temp += (digit < 16 ? 16 : 11);
        else if (base == 23)
            temp += (digit < 17 ? 17 : 12);
        else if (base == 24)
            temp += (digit < 18 ? 18 : 13);
        else if (base == 25)
            temp += (digit < 19 ? 19 : 14);
        else if (base == 26)
            temp += (digit < 20 ? 20 : 15);
        else if (base == 27)
            temp += (digit < 21 ? 21 : 16);
        else if (base == 28)
            temp += (digit < 22 ? 22 : 17);
        else if (base == 29)
            temp += (digit < 23 ? 23 : 18);
        else if (base == 30)
            temp += (digit < 24 ? 24 : 19;
        else if (base == 31)
            temp += (digit < 25 ? 25 : 20);
        else if (base == 32)
            temp += (digit < 26 ? 26 : 21);
        else if (base == 33)
            temp += (digit < 27 ? 27 : 22);
        else if (base == 34)
            temp += (digit < 28 ? 28 : 23);
        else if (base == 35)
            temp += (digit < 29 ? 29 : 24);
        else if (base == 36)
            temp += (digit < 30 ? 30 : 25);
        num[i] = temp % base + '0';
        carry = temp / base;
    }
    while (carry) {
        num = to_string(carry % base) + num;
        carry /= base;
    }
    return num;
}

int main() {
    string num;
    int base;
    cout << "Enter the number in base A: ";
    cin >> num;
    cout << "Enter the base B: ";
    cin >> base;
    cout << "Number in base B: " << convertBase(num, base) << endl;
    return 0;
}