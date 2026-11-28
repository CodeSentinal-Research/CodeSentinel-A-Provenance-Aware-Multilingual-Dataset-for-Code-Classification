#include <iostream>
using namespace std;

int main() {
    int m;
    cin >> m;
    char grade = m >= 90 ? 'A' : m >= 80 ? 'B' : m >= 70 ? 'C' : m >= 60 ? 'D' : 'F';
    cout << grade << endl;
    return 0;
}
