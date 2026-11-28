#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Contact {
    string name;
    string phoneNumber;
};

vector<Contact> contacts;

void addContact(string name, string phoneNumber) {
    contacts.push_back(Contact{name, phoneNumber});
}

vector<Contact> searchContactsByNamePrefix(string prefix) {
    vector<Contact> results;
    for (auto& contact : contacts) {
        if (contact.name.find(prefix) == 0) {
            results.push_back(contact);
        }
    }
    return results;
}

int main() {
    addContact("John", "1234567890");
    addContact("Alice", "0987654321");
    addContact("Bob", "1112223333");

    string prefix;
    cin >> prefix;

    auto results = searchContactsByNamePrefix(prefix);

    for (auto& contact : results) {
        cout << "Name: " << contact.name << ", Phone: " << contact.phoneNumber << endl;
    }

    return 0;
}