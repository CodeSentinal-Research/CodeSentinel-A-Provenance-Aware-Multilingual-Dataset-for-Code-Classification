Here is the code:

#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    int arr[N];
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    for(int i = 1; i < N - 1; i++) {
        if(arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) {
            cout << i;
            return 0;
        }
    }
    if(arr[0] > arr[1]) {
        cout << 0;
    } else if (arr[N - 1] > arr[N - 2]) {
        cout << N - 1;
    }
    return 0;
}

This code will work for the given problem as described. It first takes the number of elements as input, then it takes those elements as input and stores them in an array. It then checks each element in the array to see if it is greater than its two neighbors. If it finds a peak element, it prints the index of that element. If no peak element is found, it prints the index of the first and the last element. The constraints of the problem are not being checked as the problem doesn't mention any particular index constraints for the input array.