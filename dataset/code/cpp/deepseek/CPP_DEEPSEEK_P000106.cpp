Here is the complete C++ code for the problem:

#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    int arr[N];
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    for(int i = 0; i < N/2; i++) {
        int temp = arr[i];
        arr[i] = arr[N-i-1];
        arr[N-i-1] = temp;
    }

    for(int i = 0; i < N; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
In this code, we first take the input for the number of elements in the array. Then we take all elements one by one from the user input and store them in the array. After that, we swap the elements of the array in a way that the first element is swapped with the last element, the second with the second last and so on. Finally, we print the reversed array.