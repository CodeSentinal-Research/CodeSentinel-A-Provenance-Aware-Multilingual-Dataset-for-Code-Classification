#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> readBinaryWatch(int turnedOn) {
    vector<string> result;
    for (int h = 0; h < 12; ++h) {
        for (int m = 0; m < 60; ++m) {
            if (__builtin_popcount(h) + __builtin_popcount(m) == turnedOn) {
                string time = to_string(h) + ":";
                if (m < 10) time += "0";
                time += to_string(m);
                result.push_back(time);
            }
        }
    }
    return result;
}

int main() {
    int n;
    cin >> n;
    vector<string> result = readBinaryWatch(n);
    for (const string& t : result) {
        cout << t << endl;
    }
    return 0;
}
