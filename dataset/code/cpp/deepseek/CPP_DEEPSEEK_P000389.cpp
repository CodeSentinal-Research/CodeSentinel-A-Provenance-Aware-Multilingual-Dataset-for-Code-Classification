#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

struct Employee {
    string name;
    string department;
};

int main() {
    unordered_map<string, vector<Employee>> deptMap;
    int n;
    cin >> n;

    for(int i=0; i<n; i++) {
        Employee emp;
        cin >> emp.name >> emp.department;
        deptMap[emp.department].push_back(emp);
    }

    string deptName;
    cin >> deptName;

    if(deptMap.find(deptName) != deptMap.end()) {
        for(Employee emp: deptMap[deptName]) {
            cout << emp.name << " " << emp.department << endl;
        }
    } else {
        cout << "No Records Found" << endl;
    }

    return 0;
}