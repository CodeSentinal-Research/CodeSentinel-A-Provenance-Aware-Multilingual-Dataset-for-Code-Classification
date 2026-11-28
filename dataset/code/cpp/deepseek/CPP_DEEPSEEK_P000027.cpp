#include <iostream>
using namespace std;

int main() {
    long long n;
    cout << "Enter a non-negative integer: ";
    cin >> n;

    int count = 0;
    if(n == 0) {
        count = 1;
    } else {
        while(n != 0) {
            n /= 10;
            count++;
        }
    }

    cout << "Number of digits: " << count << endl;

    return 0;
}
This program first gets an input from the user, then counts the number of digits in the input number. The count is stored in a variable called count. If the input number is 0, then the count is initialized to 1. Otherwise, the number of digits is incremented by one for each iteration while the number is divided by 10 (this effectively removes the last digit from the number). Finally, the count is printed out.