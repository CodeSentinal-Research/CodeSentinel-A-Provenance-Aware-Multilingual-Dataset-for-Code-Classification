Here is the code:

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Employee {
    string name;
    double salary;
};

bool compareSalary(const Employee& a, const Employee& b) {
    return a.salary < b.salary;
}

void searchEmployees(vector<Employee>& employees, double minSalary, double maxSalary) {
    double lowerBound = minSalary;
    double upperBound = maxSalary;

    vector<Employee> matchingEmployees;
    for (Employee& employee : employees) {
        if (employee.salary >= lowerBound && employee.salary <= upperBound) {
            matchingEmployees.push_back(employee);
        }
    }

    cout << "Matching employee records:" << endl;
    for (Employee& employee : matchingEmployees) {
        cout << "Name: " << employee.name << ", Salary: " << employee.salary << endl;
    }
}

int main() {
    int numEmployees;
    cout << "Enter the number of employees: ";
    cin >> numEmployees;

    vector<Employee> employees;
    for (int i = 0; i < numEmployees; i++) {
        Employee employee;
        cout << "Enter the name and salary of employee " << (i + 1) << ": ";
        cin >> employee.name >> employee.salary;
        employees.push_back(employee);
    }

    double minSalary, maxSalary;
    cout << "Enter the minimum salary: ";
    cin >> minSalary;
    cout << "Enter the maximum salary: ";
    cin >> maxSalary;

    sort(employees.begin(), employees.end(), compareSalary);

    searchEmployees(employees, minSalary, maxSalary);

    return 0;
}

This program first reads the number of employees and their details. It then sorts the employees by salary and performs a search for employees whose salaries fall within the given range. The matching employees' details are then printed out.