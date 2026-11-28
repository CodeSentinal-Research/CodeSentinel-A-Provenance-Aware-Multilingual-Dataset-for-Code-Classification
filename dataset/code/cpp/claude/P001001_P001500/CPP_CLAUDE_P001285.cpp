#include <iostream>
#include <iomanip>
using namespace std;
class Solution {
public:
    double calculate(double a, char op, double b) {
        if (op=='+') return a+b;
        if (op=='-') return a-b;
        if (op=='*') return a*b;
        if (op=='/') return b!=0 ? a/b : 0;
        return 0;
    }
};
int main() {
    double a, b; char op;
    cin >> a >> op >> b;
    if (op=='/' && b==0) { cout << "Division by zero\n"; return 0; }
    cout << fixed << setprecision(2) << Solution().calculate(a,op,b) << "\n";
}
