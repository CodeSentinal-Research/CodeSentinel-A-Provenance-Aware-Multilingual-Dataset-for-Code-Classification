#include <iostream>
#include <vector>

using namespace std;

void generateGray(int n, vector<int> &gray) {
    gray.push_back(0);
    if (n == 0) return;

    generateGray(n - 1, gray);

    int curr = 1 << (n - 1);
    for (int i = gray.size() - 1; i >= 0; i--) {
        gray.push_back(gray[i] | curr);
    }
}

int main() {
    int n;
    cin >> n;
    if (n < 1 || n > 16) {
        cout << "Invalid input";
        return 0;
    }

    vector<int> gray;
    generateGray(n, gray);

    for (int i = 0; i < gray.size(); i++) {
        cout << gray[i] << " ";
    }

    return 0;
}