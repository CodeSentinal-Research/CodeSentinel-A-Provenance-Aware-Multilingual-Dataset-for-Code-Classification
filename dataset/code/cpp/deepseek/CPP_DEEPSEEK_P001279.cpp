Here is the C++ code:

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string solve(int N, int K) {
    string res = "";
    while (K > 0) {
        if (K >= 20) {
            res += 'z';
            K -= 20;
        } else if (K >= 10) {
            res += 'a';
            K -= 10;
        } else {
            res += ('0' + K);
            K = 0;
        }
    }
    return res;
}

int main() {
    int N, K;
    cin >> N >> K;
    cout << solve(N, K);
    return 0;
}

In the `solve` function, we start by initializing an empty string `res`. We then enter a while loop that continues until `K` is less than or equal to 0. Inside the loop, we first check if `K` is greater than or equal to 20, and if it is, we append 'z' to `res` and subtract 20 from `K`. Then we do the same for 'a' and subtract 10 from `K`. If `K` is still greater than or equal to 10, we append the corresponding digit to `res` and set `K` to 0. Finally, we return the string `res`.