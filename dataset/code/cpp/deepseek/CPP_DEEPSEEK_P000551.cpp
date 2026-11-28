Here is the C++ code for the problem:

#include <iostream>
#include <queue>

using namespace std;

void generateBinary(int N) {
    queue<string> q;
    q.push("1");
    while(N--) {
        string s = q.front();
        q.pop();
        cout << s << " ";
        string s1 = s + "0";
        string s2 = s + "1";
        q.push(s1);
        q.push(s2);
    }
}

int main() {
    int N;
    cin >> N;
    generateBinary(N);
    return 0;
}

This code uses a queue to store the binary numbers. The binary number starts with "1" and then in each iteration, it generates two new binary numbers by appending "0" and "1" to the end of the existing binary number. The two new binary numbers are then pushed into the queue. The process continues until all numbers from 1 to N are processed.