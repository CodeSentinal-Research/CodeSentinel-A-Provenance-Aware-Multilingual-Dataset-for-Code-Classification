#include <iostream>
#include <string>
#include <stack>
using namespace std;
string decodeString(string s) {
    stack<int> num_stack;
    stack<string> str_stack;
    string curr = "";
    int num = 0;
    for(char c : s) {
        if(isdigit(c)) { num = num*10 + (c-'0'); }
        else if(c == '[') { num_stack.push(num); str_stack.push(curr); curr = ""; num = 0; }
        else if(c == ']') {
            string tmp = str_stack.top(); str_stack.pop();
            int count = num_stack.top(); num_stack.pop();
            for(int i=0; i<count; i++) tmp += curr;
            curr = tmp;
        } else { curr += c; }
    }
    return curr;
}
int main() {
    string s; cin >> s;
    cout << decodeString(s) << endl;
    return 0;
}
