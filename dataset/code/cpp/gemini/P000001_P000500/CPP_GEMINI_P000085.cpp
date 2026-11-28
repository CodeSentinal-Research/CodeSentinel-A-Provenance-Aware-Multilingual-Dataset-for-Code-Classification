#include <iostream>

char calculateGrade(double marks) {
    if (marks >= 90.0) return 'A';
    else if (marks >= 80.0) return 'B';
    else if (marks >= 70.0) return 'C';
    else if (marks >= 60.0) return 'D';
    else if (marks >= 50.0) return 'E';
    else return 'F';
}

int main() {
    double marks;
    if (std::cin >> marks) {
        std::cout << calculateGrade(marks) << "\n";
    }
    return 0;
}