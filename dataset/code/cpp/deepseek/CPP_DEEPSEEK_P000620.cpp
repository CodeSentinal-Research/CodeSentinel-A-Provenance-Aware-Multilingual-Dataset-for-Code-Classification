Here is the complete C++ code:

#include <iostream>
#include <list>

using namespace std;

int solve(list<int> &l) {
    int res = 0;
    list<int>::iterator it;
    for(it = l.begin(); it != l.end(); ++it) {
        res = res*2 + *it;
    }
    return res;
}

int main() {
    list<int> l;
    int n;
    cout << "Enter the number of nodes: ";
    cin >> n;
    cout << "Enter the binary number: ";
    int temp;
    for(int i=0; i<n; i++) {
        cin >> temp;
        l.push_back(temp);
    }
    cout << "Decimal value is: " << solve(l) << endl;
    return 0;
}

This code receives the number of nodes in the linked list and the linked list itself as input. The `solve` function is responsible for converting the binary linked list to a decimal number. It iterates over the list, multiplying the result by 2 and adding the current value. When all values have been processed, it returns the result. The `main` function is the entry point of the program, where the user is prompted to enter the number of nodes and the linked list itself. The `solve` function is then called with the list as an argument, and the result is printed to the console.