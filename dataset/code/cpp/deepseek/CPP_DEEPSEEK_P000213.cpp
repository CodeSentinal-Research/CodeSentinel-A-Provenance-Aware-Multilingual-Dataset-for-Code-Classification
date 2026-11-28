Here is the C++ code:

#include <iostream>
#include <set>
#include <limits>
using namespace std;

int main() {
    int n;
    cin >> n;

    set<int> s;
    int max_num = numeric_limits<int>::min();
    int second_max_num = numeric_limits<int>::min();
    int third_max_num = numeric_limits<int>::min();

    for(int i=0; i<n; i++) {
        int num;
        cin >> num;

        s.insert(num);

        if(num > max_num) {
            third_max_num = second_max_num;
            second_max_num = max_num;
            max_num = num;
        } else if(num > second_max_num && num < max_num) {
            third_max_num = second_max_num;
            second_max_num = num;
        } else if(num > third_max_num && num < second_max_num) {
            third_max_num = num;
        }
    }

    if(s.size() < 3) {
        cout << max_num << endl;
    } else {
        cout << third_max_num << endl;
    }

    return 0;
}
This code takes N as input, then iterates through the array, inserting each number into a set which automatically removes duplicate entries. It then checks if each number is greater than the current max, second max, or third max and updates them accordingly. Finally, it prints the third maximum number if it exists, otherwise it prints the maximum.