Here's the C++ code that will solve the problem:

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> nextSmallerElement(vector<int> arr) {
    stack<int> s;
    vector<int> result(arr.size(), -1);

    for (int i = 0; i < arr.size(); i++) {
        while (!s.empty() && arr[s.top()] > arr[i]) {
            result[s.top()] = arr[i];
            s.pop();
        }
        s.push(i);
    }

    return result;
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> result = nextSmallerElement(arr);

    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << "\n";

    return 0;
}

This program uses a stack to find the next smaller element for each element in the array. It pushes the current element into the stack if the stack is not empty and the top element is greater than the current element. If the stack is empty or the top element is smaller, it pops the element from the stack and sets the result to the current element. This process is repeated for all elements in the array.