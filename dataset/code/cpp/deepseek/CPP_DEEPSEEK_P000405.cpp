Sure, here's the C++ code:

#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Course {
    string name;
    string instructor;
};

int main() {
    int n;
    cin >> n;

    vector<Course> courses(n);
    for (int i = 0; i < n; i++) {
        cin >> courses[i].name >> courses[i].instructor;
    }

    string instructorName;
    cin >> instructorName;

    for (const Course& course : courses) {
        if (course.instructor == instructorName) {
            cout << course.name << '\n';
        }
    }

    return 0;
}

This program first reads the number of courses and then each course's name and instructor. It then reads the name of the instructor to search for. It then prints all the courses taught by the specified instructor.