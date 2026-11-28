Here is the C++ code that can solve the problem:

#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

string clearDigits(string s) {
    stack<char> st;
    for(int i=0; i<s.length(); i++){
        if(s[i]>='a' && s[i]<='z'){
            st.push(s[i]);
        }
        else if(s[i]>='0' && s[i]<='9'){
            if(!st.empty() && st.top()>='a' && st.top()<='z'){
                st.pop();
            }
            else{
                s[i]='0'+s[i];
            }
        }
    }

    while(!st.empty()){
        s=s.substr(0,s.length()-1);
        st.pop();
    }

    return s;
}

int main() {
    string s;
    cin >> s;
    cout << clearDigits(s);
    return 0;
}

In this code, we use a stack to keep track of the lowercase English letters. For each character in the string, we push it into the stack if it's a lowercase letter. If it's a digit, we pop the top element from the stack (which is the lowercase letter on its left). If the stack is empty (i.e., there's no lowercase letter on its left), we discard the digit. After processing all characters, we pop all the elements from the stack and concatenate them to form the final string. The time complexity is O(n) where n is the length of the string.