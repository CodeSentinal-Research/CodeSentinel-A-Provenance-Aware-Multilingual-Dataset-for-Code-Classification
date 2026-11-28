#include <iostream>
#include <sstream>
#include <stack>

using namespace std;

bool isValid(string data) {
    stack<string> st;
    stringstream ss(data);
    string item;

    while (getline(ss, item, ',')) {
        if (item == "#") {
            if (st.empty()) {
                return false;
            }
            st.pop();
        } else {
            st.push(item);
        }
    }

    return st.empty();
}

int main() {
    string serialization;
    cout << "Enter a serialization string: ";
    getline(cin, serialization);

    if (isValid(serialization)) {
        cout << "Valid" << endl;
    } else {
        cout << "Invalid" << endl;
    }

    return 0;
}