#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct User {
    string username;
};

vector<string> searchUsers(vector<User>& users, string prefix) {
    vector<string> usernames;
    for (User user : users) {
        if (user.username.find(prefix) == 0) {
            usernames.push_back(user.username);
        }
    }
    return usernames;
}

int main() {
    vector<User> users = { {"alice"}, {"bob"}, {"charlie"}, {"dave"}, {"eve"} };
    string prefix = "b";
    vector<string> usernames = searchUsers(users, prefix);
    for (string username : usernames) {
        cout << username << endl;
    }
    return 0;
}