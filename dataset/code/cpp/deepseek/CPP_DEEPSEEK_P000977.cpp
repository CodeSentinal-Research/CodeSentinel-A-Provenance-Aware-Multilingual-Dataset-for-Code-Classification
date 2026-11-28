#include <iostream>
#include <cmath>
#include <vector>

bool isCollinear(int x1, int y1, int x2, int y2, int x3, int y3) {
    double slope1 = (double)(y2-y1) / (x2-x1);
    
    double slope2 = (double)(y3-y2) / (x3-x2);
    
    return slope1 == slope2;
}

int main() {
    int x1, y1, x2, y2, x3, y3;
    
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    
    if (isCollinear(x1, y1, x2, y2, x3, y3)) {
        cout << "True";
    } else {
        cout << "False";
    }
    
    return 0;
}