#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    string S;
    cout << "Enter a string: ";
    cin >> S;

    sort(S.begin(), S.end());

    cout << "Sorted string: " << S << endl;

    return 0;
}