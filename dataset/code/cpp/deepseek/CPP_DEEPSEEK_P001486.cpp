#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

int compareVersion(string version1, string version2) {
    vector<int> v1, v2;
    stringstream ss1(version1), ss2(version2);
    string temp;
    char dot;

    while (getline(ss1, temp, '.')) {
        v1.push_back(stoi(temp));
    }

    while (getline(ss2, temp, '.')) {
        v2.push_back(stoi(temp));
    }

    while (v1.size() < v2.size()) {
        v1.push_back(0);
    }

    while (v2.size() < v1.size()) {
        v2.push_back(0);
    }

    for (int i = 0; i < v1.size(); i++) {
        if (v1[i] > v2[i]) {
            return 1;
        } else if (v1[i] < v2[i]) {
            return -1;
        }
    }

    return 0;
}

int main() {
    string version1, version2;
    cin >> version1 >> version2;

    cout << compareVersion(version1, version2) << endl;

    return 0;
}