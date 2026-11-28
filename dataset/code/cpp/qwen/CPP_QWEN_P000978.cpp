#include <iostream>
#include <cmath>
using namespace std;

long long distSq(long long x1, long long y1, long long x2, long long y2) {
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

int main() {
    long long x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    
    long long d1 = distSq(x1, y1, x2, y2);
    long long d2 = distSq(x2, y2, x3, y3);
    long long d3 = distSq(x3, y3, x1, y1);
    
    if (d1 == 0 || d2 == 0 || d3 == 0) {
        cout << "Not a Triangle" << endl;
        return 0;
    }
    
    if (d1 == d2 && d2 == d3) cout << "Equilateral" << endl;
    else if (d1 == d2 || d2 == d3 || d3 == d1) cout << "Isosceles" << endl;
    else cout << "Scalene" << endl;
    
    return 0;
}
