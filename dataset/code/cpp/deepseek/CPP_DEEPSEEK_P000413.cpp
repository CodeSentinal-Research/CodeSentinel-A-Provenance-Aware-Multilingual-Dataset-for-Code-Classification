#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Employee {
    string name;
    string department;
    bool active;
};

int main() {
    int numEmployees;
    cin >> numEmployees;

    vector<Employee> employees(numEmployees);

    for (int i = 0; i < numEmployees; i++) {
        cin >> employees[i].name >> employees[i].department >> employees[i].active;
    }

    string queryDepartment;
    cin >> queryDepartment;

    for (const Employee& employee : employees) {
        if (employee.department == queryDepartment && employee.active) {
            cout << employee.name << '\n';
        }
    }

    return 0;
}