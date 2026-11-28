#include <iostream>
using namespace std;

int guessNumber(int low, int high) {
    if (low >= high) {
        return low;
    }

    int mid = low + (high - low) / 2;
    int res = guess(mid);

    if (res == 0) {
        return mid;
    } else if (res < 0) {
        return guessNumber(low, mid);
    } else {
        return guessNumber(mid + 1, high);
    }
}

int main() {
    srand(time(NULL));
    int n = rand() % 2147483647; 
    int high = 2147483647, low = 1;

    cout << "The hidden number is: " << guessNumber(low, high) << endl;

    return 0;
}
This code first generates a random number between 1 and n (exclusive). Then it uses binary search to find the hidden number. The guess function is assumed to be provided by the API.