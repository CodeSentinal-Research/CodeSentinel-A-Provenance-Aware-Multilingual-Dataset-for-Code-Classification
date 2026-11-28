#include <iostream>
using namespace std;

int main() {
    int seconds;
    cout << "Enter the number of seconds: ";
    cin >> seconds;

    int hours = seconds / 3600;
    int remainingSeconds = seconds % 3600;
    int minutes = remainingSeconds / 60;
    int remainingSecondsInMinutes = remainingSeconds % 60;

    cout << "Hours: " << hours << endl;
    cout << "Minutes: " << minutes << endl;
    cout << "Seconds: " << remainingSecondsInMinutes << endl;

    return 0;
}