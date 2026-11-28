#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

struct Employee {
    string name;
    string joiningDate;
};

vector<Employee> parseEmployees(istringstream& stream) {
    int n;
    stream >> n;
    vector<Employee> employees(n);
    for (int i = 0; i < n; i++) {
        stream >> employees[i].name >> employees[i].joiningDate;
    }
    return employees;
}

void printEmployees(const vector<Employee>& employees, ostream& stream) {
    for (const auto& employee : employees) {
        stream << employee.name << ' ' << employee.joiningDate << endl;
    }
}

vector<Employee> searchEmployeesBefore(vector<Employee>& employees, const string& date) {
    vector<Employee> result;
    for (auto& employee : employees) {
        if (employee.joiningDate < date) {
            result.push_back(employee);
        }
    }
    return result;
}

int main() {
    istringstream stream(R"(4
John 2005-06-01
Adam 2008-09-02
Robert 2010-11-03
Alex 2012-12-04
)");
    vector<Employee> employees = parseEmployees(stream);
    string date;
    cin >> date;
    vector<Employee> result = searchEmployeesBefore(employees, date);
    printEmployees(result, cout);
    return 0;
}

This program takes an input stream of employee records and a date from the user. It parses the employee records, searches for employees who joined before the specified date, and prints the matching records.