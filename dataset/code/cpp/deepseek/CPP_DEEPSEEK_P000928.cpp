Here is the required C++ code:

#include <iostream>
#include <bitset>
#include <string>

using namespace std;

string binaryAddition(string A, string B) {
    int numA = bitset<32>(A).to_ulong();
    int numB = bitset<32>(B).to_ulong();

    int sum = numA + numB;
    bitset<32> res(sum);

    return res.string();
}

int main() {
    string A, B;

    cin >> A >> B;

    cout << binaryAddition(A, B);

    return 0;
}

This program first converts the input binary strings to integers using the bitset library. It then performs the addition and converts the result back to a binary string using the bitset library again.