#include <bits/stdc++.h>
using namespace std;
int main() {
    string s; getline(cin, s);
    istringstream iss(s);
    int c = 0; string w;
    while(iss >> w) c++;
    cout << c << endl;
    return 0;
}
