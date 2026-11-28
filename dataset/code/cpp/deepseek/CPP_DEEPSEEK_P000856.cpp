#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter an integer: ";
    cin >> n;

    int count = 0;
    while (n >= 0)
    {
        n >>= 1;
        count += n;
    }

    cout << "Trailing zeros in binary representation: " << count << endl;
    return 0;
}