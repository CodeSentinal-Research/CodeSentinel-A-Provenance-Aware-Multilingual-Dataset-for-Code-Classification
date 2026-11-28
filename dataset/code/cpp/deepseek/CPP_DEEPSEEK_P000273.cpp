#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isValid(string S) {
    stack<char> s;
    for(int i=0; i<S.length(); i++){
        char c = S[i];
        if(c == '(' || c == '{' || c == '['){
            s.push(c);
        }
        else{
            if(s.empty()){
                return false;
            }
            char top = s.top();
            if((c == ')' && top != '(') || (c == '}' && top != '{') || (c == ']' && top != '[')){
                return false;
            }
            s.pop();
        }
    }
    return s.empty();
}

int main() {
    string S;
    cin >> S;
    if(isValid(S)) cout << "Valid";
    else cout << "Invalid";
    return 0;
}