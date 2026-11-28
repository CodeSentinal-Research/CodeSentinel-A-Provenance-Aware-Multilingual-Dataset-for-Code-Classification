#include <iostream>
using namespace std;

bool isArmstrong(long long N) {
    long long sum = 0, temp = N;
    int digits = 0;
    
    while(temp != 0) {
        temp /= 10;
        digits++;
    }
    
    temp = N;
    while(temp != 0) {
        int remainder = temp % 10;
        sum += pow(remainder, digits);
        temp /= 10;
    }
    
    if(N == sum)
        return true;
    else
        return false;
}

int main() {
    long long N;
    cout << "Enter a number: ";
    cin >> N;
    
    if(isArmstrong(N))
        cout << "true";
    else
        cout << "false";
    
    return 0;
}
This C++ code will take an input number from user and check whether it's an Armstrong number or not. The isArmstrong function checks each digit of the number and sums up their power and if the sum is equal to the number then it's an Armstrong number.