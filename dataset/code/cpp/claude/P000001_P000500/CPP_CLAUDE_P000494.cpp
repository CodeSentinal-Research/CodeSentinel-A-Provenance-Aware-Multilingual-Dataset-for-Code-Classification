#include <iostream>
#include <iomanip>
using namespace std;
class Solution {
public:
    double celsiusToFahrenheit(double c) { return c * 9.0/5.0 + 32.0; }
};
int main() {
    double c; cin >> c;
    cout << fixed << setprecision(2) << Solution().celsiusToFahrenheit(c) << "\n";
}
