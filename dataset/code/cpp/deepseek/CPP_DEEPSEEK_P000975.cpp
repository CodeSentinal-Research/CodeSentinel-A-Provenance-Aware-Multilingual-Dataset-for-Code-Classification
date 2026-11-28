#include <iostream>

int main() {
    int x1, y1, x2, y2;
    
    std::cout << "Enter the coordinates of the endpoints of the line segment:" << std::endl;
    std::cin >> x1 >> y1 >> x2 >> y2;
    
    int midX = (x1 + x2) / 2;
    int midY = (y1 + y2) / 2;
    
    std::cout << "The coordinates of the midpoint are: (" << midX << ", " << midY << ")" << std::endl;
    
    return 0;
}