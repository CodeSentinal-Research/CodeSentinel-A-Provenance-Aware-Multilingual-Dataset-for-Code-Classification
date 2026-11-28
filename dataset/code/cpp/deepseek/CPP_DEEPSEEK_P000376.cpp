Here is the C++ code to solve the problem:

#include <iostream>
#include <map>
using namespace std;

struct Customer {
    string name;
    string mobile;
};

int main() {
    int n;
    cin >> n;

    map<string, string> customerRecords;

    for(int i = 0; i < n; i++) {
        Customer c;
        cin >> c.name >> c.mobile;
        customerRecords[c.mobile] = c.name;
    }

    string mobileNumber;
    cin >> mobileNumber;

    if (customerRecords.find(mobileNumber) != customerRecords.end()) {
        cout << "Name: " << customerRecords[mobileNumber] << endl;
    } else {
        cout << "Customer Not Found" << endl;
    }

    return 0;
}

This code reads the number of customers and customer records then reads the mobile numbers and names of customers. After that, it reads the mobile number to be searched. It uses a map to store customer records and then finds the customer with the provided mobile number. If the customer is found, it prints their name, otherwise it prints "Customer Not Found".