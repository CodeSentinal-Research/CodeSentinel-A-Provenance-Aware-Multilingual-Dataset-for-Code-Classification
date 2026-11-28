Here is the JavaScript code for the problem:

function findTriangleType(a, b, c) {
    // Check if the inputs are positive integers
    if (a <= 0 || b <= 0 || c <= 0) {
        console.log("Inputs must be positive integers");
        return;
    }

    // Check if the inputs can form a triangle
    if (a + b <= c || a + c <= b || b + c <= a) {
        console.log("The given sides do not form a triangle");
        return;
    }

    // Check if the sides form an equilateral triangle
    if (a == b && b == c) {
        console.log("Equilateral");
    }
    // Check if the sides form an isosceles triangle
    else if (a == b || b == c || c == a) {
        console.log("Isosceles");
    }
    // Otherwise it is a scalene triangle
    else {
        console.log("Scalene");
    }
}
This JavaScript function takes three arguments representing the sides of a triangle and checks whether they can form a triangle, then determines the type of triangle based on the lengths of its sides.