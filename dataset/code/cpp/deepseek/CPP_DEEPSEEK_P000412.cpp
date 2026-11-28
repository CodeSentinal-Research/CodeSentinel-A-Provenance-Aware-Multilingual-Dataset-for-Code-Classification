Here is a simple C++ code to solve the problem. This code uses a hash map (unordered_map) to store the contact list. The key is the lowercase version of the contact name, and the value is the contact information. When a search is performed, it checks if the lowercase version of the input name exists in the hash map.

#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

struct Contact {
    string name;
    string phone;
};

int main() {
    int n;
    cin >> n;
    unordered_map<string, Contact> contacts;
    for (int i = 0; i < n; i++) {
        Contact c;
        cin >> c.name >> c.phone;
        transform(c.name.begin(), c.name.end(), c.name.begin(), ::tolower);
        contacts[c.name] = c;
    }
    string search;
    cin >> search;
    transform(search.begin(), search.end(), search.begin(), ::tolower);
    if (contacts.count(search)) {
        cout << "Name: " << contacts[search].name << ", Phone: " << contacts[search].phone << endl;
    } else {
        cout << "No contact found" << endl;
    }
    return 0;
}
This code reads the number of contacts and contacts from the input. Then it reads a search name from the input. The search name is also converted to lowercase for case-insensitive comparison. If the search name exists in the hash map, the contact information is printed; otherwise, a message indicating no contact was found is printed.