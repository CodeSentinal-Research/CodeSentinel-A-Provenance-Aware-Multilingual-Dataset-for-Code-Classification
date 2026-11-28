#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    map<string, string> userRecords;

    userRecords["user1"] = "user1@example.com";
    userRecords["user2"] = "user2@example.com";
    userRecords["user3"] = "user3@example.com";

    string username;
    cout << "Enter username: ";
    cin >> username;

    map<string, string>::iterator it = userRecords.find(username);
    if(it != userRecords.end()) {
        cout << "Email: " << it->second << endl;
    } else {
        cout << "User Not Found" << endl;
    }

    return 0;
}

This code creates a map where the key is the username and the value is the email. The map is then used to search for the email associated with a given username. If the username is found in the map, the associated email is printed. Otherwise, "User Not Found" is printed.