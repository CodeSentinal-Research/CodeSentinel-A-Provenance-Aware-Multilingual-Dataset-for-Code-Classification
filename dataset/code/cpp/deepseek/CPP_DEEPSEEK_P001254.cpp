Here is the code:

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    sort(arr.begin(), arr.end(), [](int a, int b) {
        return to_string(a) + to_string(b) > to_string(b) + to_string(a);
    });
    
    for(int i = 0; i < n; i++) {
        cout << arr[i];
        if(i != n - 1) {
            cout << " ";
        }
    }
    
    return 0;
}

This code first takes the number of elements `n` as input. Then it takes `n` numbers as input and stores them in a vector. The sort function from the algorithm library is used to sort the vector in descending order. The lambda function within the sort function is used to compare two numbers and decide which one should be placed before the other in the sorted sequence. 

Finally, the sorted numbers are printed out.