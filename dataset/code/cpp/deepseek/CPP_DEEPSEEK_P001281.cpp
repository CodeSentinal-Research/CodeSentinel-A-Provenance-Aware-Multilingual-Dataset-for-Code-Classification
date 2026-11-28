#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string removeKdigits(string num, int k) {
    num.erase(0, min(num.find_first_not_of('0'), num.size()));

    for(int i=0; i<k; i++) {
        for(int j=0; j<num.size()-i-1; j++) {
            if(num[j] > num[j+1]) {
                swap(num[j], num[j+1]);
            }
        }
    }

    while(num.size() > 1 && num[0] == '0') {
        num.erase(0, 1);
    }

    return num.empty() ? "0" : num;
}

int main() {
    string num;
    int k;
    cin >> num >> k;

    cout << removeKdigits(num, k) << endl;

    return 0;
}