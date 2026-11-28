#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    int count[10] = {0};
    for(int i = 1; i <= N; i++) {
        int sum = 0;
        int num = i;
        while(num) {
            sum += num % 10;
            num /= 10;
        }
        count[sum]++;
    }

    int max_count = 0;
    for(int i = 0; i < 10; i++) {
        max_count = max(max_count, count[i]);
    }

    cout << max_count << endl;

    return 0;
}
This code reads the number N, then for each integer from 1 to N, it calculates the sum of its digits. It then increments the corresponding index in the count array. The count array keeps track of the frequency of each digit sum. Finally, it finds the maximum frequency in the count array and prints it as the output.