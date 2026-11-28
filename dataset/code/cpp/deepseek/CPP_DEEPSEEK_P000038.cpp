#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double principal, rate, time;
    cout << "Enter principal amount: ";
    cin >> principal;
    cout << "Enter rate of interest: ";
    cin >> rate;
    cout << "Enter time period in years: ";
    cin >> time;
    
    double compoundInterest = principal * pow((1 + rate / 100), time);
    
    cout << "The compound interest is: " << compoundInterest;
    
    return 0;
}