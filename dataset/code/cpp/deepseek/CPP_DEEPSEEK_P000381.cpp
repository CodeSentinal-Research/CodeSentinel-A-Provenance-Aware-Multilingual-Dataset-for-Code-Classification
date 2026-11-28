#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Contact {
    string name;
    string phone;
};

bool searchContact(vector<Contact>& contacts, string name) {
    for (Contact contact : contacts) {
        if (contact.name == name) {
            cout << "Name: " << contact.name << endl;
            cout << "Phone: " << contact.phone << endl;
            return true;
        }
    }
    cout << "Contact Not Found" << endl;
    return false;
}

int main() {
    vector<Contact> contacts = {
        {"John", "1234567890"},
        {"Jane", "0987654321"},
        {"Alice", "1122334455"},
    };

    string name;
    cout << "Enter contact name to search: ";
    cin >> name;

    if (searchContact(contacts, name)) {
        cout << endl;
    }

    return 0;
}