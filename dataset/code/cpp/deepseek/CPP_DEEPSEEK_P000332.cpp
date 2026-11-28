#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    string S, order;
    cin >> order >> S;

    sort(S.begin(), S.end(), [&](char a, char b) {
        return order.find(a) < order.find(b);
    });

    cout << S;
    return 0;
}