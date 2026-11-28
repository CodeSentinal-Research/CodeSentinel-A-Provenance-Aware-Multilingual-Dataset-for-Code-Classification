#include <iostream>
using namespace std;

int main() {
    float principal, rate, time, interest;
    
    cout << "Enter the principal amount: ";
    cin >> principal;
    
    cout << "Enter the rate of interest: ";
    cin >> rate;
    
    cout << "Enter the time for which interest is to be calculated: ";
    cin >> time;
    
    interest = (principal * rate * time) / 100;
    
    cout << "The simple interest is: " << interest;
    
    return 0;
}