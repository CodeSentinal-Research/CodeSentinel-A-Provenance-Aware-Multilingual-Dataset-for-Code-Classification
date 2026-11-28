#include <iostream>
using namespace std;

class Circle
{
    public:
    const double pi = 3.14159;
    float radii;
};

class Square
{
    public:
    int side;
};

class Rectangle
{
    public:
    int length;
    int breadth;
};

class Calculate: public Circle, public Square, public Rectangle
{
    public:
    void Calculation()
    {
        cout << "Enter radius of the circle:- ";
        cin >> radii;
        cout << "Area of cirlce :- " << (pi * (radii,2)) << endl;

        cout << "Enter the area of the Square:- ";
        cin >> side;
        cout << "Area of Square :- " << (side * side) << endl;

        cout << "Enter the length of the rectangle :- ";
        cin >> length;
        cout << "Enter the breadth of the breadth :- ";
        cin >> breadth; 
        cout << "Area of Rectangle :- " << (length * breadth) << endl;
    }  
}; 

int main()
{
    Calculate ans;
    ans.Calculation();
    return 0;
}