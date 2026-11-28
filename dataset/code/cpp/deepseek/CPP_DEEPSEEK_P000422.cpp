#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Student {
    double cgpa;
    int family_income;
};

bool eligibleForScholarship(Student student) {
    return student.cgpa >= 2.0 && student.family_income >= 50000;
}

int main() {
    int n;
    cin >> n;

    vector<Student> students(n);

    for (int i = 0; i < n; i++) {
        cin >> students[i].cgpa >> students[i].family_income;
    }

    vector<Student> eligibleStudents;

    for (int i = 0; i < n; i++) {
        if (eligibleForScholarship(students[i])) {
            eligibleStudents.push_back(students[i]);
        }
    }

    for (int i = 0; i < eligibleStudents.size(); i++) {
        cout << eligibleStudents[i].cgpa << " " << eligibleStudents[i].family_income << endl;
    }

    return 0;
}

This program first retrieves the number of students from the input. It then retrieves each student's CGPA and annual income from the input. It then checks each student's eligibility for the scholarship by using the `eligibleForScholarship` function. If a student is eligible for the scholarship, it is added to the `eligibleStudents` vector. Finally, the program outputs the CGPA and annual income of all eligible students.