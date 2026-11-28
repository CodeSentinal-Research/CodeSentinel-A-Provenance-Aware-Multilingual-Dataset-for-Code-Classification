Here is the C++ code that verifies the preorder serialization of a binary tree.

#include <iostream>
#include <sstream>
#include <stack>

using namespace std;

bool verify(string data)
{
    stringstream ss(data);
    string token;
    stack<string> s;

    while (getline(ss, token, ','))
    {
        if (token == "X")
        {
            if (s.empty() || s.top() == "X")
                return false;

            while (!s.empty() && s.top() != "X")
                s.pop();

            if (s.empty() || s.top() == "X")
                return false;

            s.pop();
        }
        else
            s.push(token);
    }

    return s.empty();
}

int main()
{
    string data;
    getline(cin, data);

    if (verify(data))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}

This code works by using a stack to keep track of the parent nodes. When it encounters a "X", it checks if the stack is empty or the top of the stack is "X". If either of these conditions is true, it returns false. If neither of these conditions is true, it pops from the stack and checks if the popped node is "X". This process continues until the stack is empty or the top of the stack is "X", in which case it returns false. If the stack is empty, it returns true.