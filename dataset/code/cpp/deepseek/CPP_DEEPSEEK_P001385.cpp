Here is the code to solve the problem:

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> arr(N);
    for(int i=0; i<N; i++) {
        cin >> arr[i];
    }
    vector<int> missingNumbers;
    for(int i=1; i<=N; i++) {
        if(find(arr.begin(), arr.end(), i) == arr.end()) {
            missingNumbers.push_back(i);
        }
    }
    sort(missingNumbers.begin(), missingNumbers.end());
    for(int i=0; i<missingNumbers.size(); i++) {
        cout << missingNumbers[i] << " ";
    }
    return 0;
}
This code first reads the number of elements N, then reads the array of integers. It then iterates from 1 to N and checks if the number is present in the array. If not, it adds the number to the list of missing numbers. Finally, it sorts the list of missing numbers and prints them.