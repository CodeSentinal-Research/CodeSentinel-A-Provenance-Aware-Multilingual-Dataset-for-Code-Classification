#include <iostream>
using namespace std;

int main() {
    string record;
    cin >> record;

    if (record[record.length() - 1] == 'A') {
        cout << "Yes";
    } else {
        cout << "No";
    }

    return 0;
}