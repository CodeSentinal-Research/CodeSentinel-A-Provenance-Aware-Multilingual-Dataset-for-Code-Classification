Here is the requested C++ code:

#include <iostream>
#include <unordered_map>

using namespace std;

struct Employee {
    int id;
    string name;
    double salary;
};

unordered_map<int, Employee> employees;

int main() {
    int numOfEmployees;
    cin >> numOfEmployees;

    for (int i = 0; i < numOfEmployees; i++) {
        int id;
        cin >> id;

        Employee emp;
        cin >> emp.name >> emp.salary;

        employees[id] = emp;
    }

    int idToSearch;
    cin >> idToSearch;

    if (employees.find(idToSearch) != employees.end()) {
        cout << employees[idToSearch].name << " " << employees[idToSearch].salary << endl;
    } else {
        cout << "Record Not Found" << endl;
    }

    return 0;
}

This program takes the number of employees as input, then loops through each employee and their details. It then takes the id of the employee to search for and looks up the employee in the unordered map. If the employee is found, it prints the name and salary of the employee. If not, it prints "Record Not Found".