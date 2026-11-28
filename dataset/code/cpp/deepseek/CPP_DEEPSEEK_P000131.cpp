Here is the C++ code for the given problem:

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }

    vector<int> leaders(n);
    int max_from_right = a[n-1];
    leaders[n-1] = 1;

    for(int i=n-2; i>=0; i--) {
        if(a[i] > max_from_right) {
            max_from_right = a[i];
            leaders[i] = 1;
        }
    }

    for(int i=0; i<n; i++) {
        if(leaders[i] == 1) {
            cout << a[i] << " ";
        }
    }
    cout << endl;

    return 0;
}

This code first reads the size of the array from the standard input. Then, it reads the array from the standard input. 

Then, it initializes a vector 'leaders' with all elements set to 0. The maximum element from the right is initially set to the last element of the array. 

For each element from the right, if it is greater than the maximum so far, it is set as the new maximum and 1 is added to the corresponding index in the leaders vector. 

Finally, it prints all elements in the leaders vector which have a value of 1, indicating they are the leaders in the array.