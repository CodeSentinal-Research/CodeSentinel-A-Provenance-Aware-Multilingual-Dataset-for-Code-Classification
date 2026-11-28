#include <iostream>
#include <unordered_map>

struct Student {
    int roll;
    std::string name;
    float gpa;

    Student(int roll, std::string name, float gpa) : roll(roll), name(name), gpa(gpa) {}
};

int main() {
    std::unordered_map<int, Student> students;

    students[1] = Student(1, "John", 3.5);
    students[2] = Student(2, "Mike", 3.6);
    students[3] = Student(3, "Sara", 3.7);

    int roll_number;
    std::cout << "Enter the roll number to search: ";
    std::cin >> roll_number;

    if(students.find(roll_number) != students.end()) {
        Student student = students[roll_number];
        std::cout << "Student Information: Roll Number: " << student.roll << ", Name: " << student.name << ", GPA: " << student.gpa << std::endl;
    } else {
        std::cout << "Record Not Found" << std::endl;
    }

    return 0;
}