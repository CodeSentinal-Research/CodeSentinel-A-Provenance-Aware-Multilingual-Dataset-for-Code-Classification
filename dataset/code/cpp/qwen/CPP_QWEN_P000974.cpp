#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
    long long x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    double dist = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    cout << fixed << setprecision(6) << dist << endl;
    return 0;
}
