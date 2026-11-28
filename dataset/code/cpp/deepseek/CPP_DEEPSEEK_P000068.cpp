Here is the C++ code for the problem:

#include <iostream>
using namespace std;

int main() {
    double side;

    cout << "Enter the side length of the square: ";
    cin >> side;

    while (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a number between 1 and 1000: ";
        cin >> side;
    }

    double perimeter = 4 * side;

    cout << "The perimeter of the square is: " << perimeter << endl;

    return 0;
}

This program prompts the user to enter the side length of the square and checks if the input is a number between 1 and 1000. If the input is not a number, it clears the input stream and ignores the incorrect input, then prompts again.

If the input is a valid number, it calculates the perimeter of the square and prints the result.