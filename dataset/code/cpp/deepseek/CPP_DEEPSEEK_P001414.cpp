Here is the C++ code for the problem:

#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    set<int> s;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        s.insert(abs(a));
    }
    cout << s.size() << endl;
    return 0;
}

In this code, we use a set to store the absolute values of the input integers. A set in C++ is a container that stores unique values and can be modified with the help of STL functions. The insert function is used to insert elements into the set. The size function is then used to get the number of elements in the set which is the number of distinct absolute values.