Here is a simple JavaScript solution that uses the Law of Cosines to determine the type of triangle:

function triangleType(x1, y1, x2, y2, x3, y3) {
    // Calculate the sides using the Law of Cosines
    let a = Math.sqrt(Math.pow(x2 - x1, 2) + Math.pow(y2 - y1, 2));
    let b = Math.sqrt(Math.pow(x3 - x2, 2) + Math.pow(y3 - y2, 2));
    let c = Math.sqrt(Math.pow(x1 - x3, 2) + Math.pow(y1 - y3, 2));

    // Check if the points are collinear
    if (x1 === x2 && x2 === x3 || y1 === y2 && y2 === y3) {
        return "Not a Triangle";
    }

    // Check if the triangle is valid
    if (a + b <= c || a + c <= b || b + c <= a) {
        return "Not a Triangle";
    }

    // Check the type of the triangle
    if (a === b && b === c) {
        return "Equilateral";
    } else if (a === b || a === c || b === c) {
        return "Isosceles";
    } else {
        return "Scalene";
    }
}

This function takes as input the coordinates of three points (x1, y1), (x2, y2), and (x3, y3). It calculates the lengths of the sides of the triangle using the Law of Cosines, and then checks if the points are collinear. It then checks if the triangle is valid by ensuring that the sum of the lengths of any two sides is greater than the length of the third side. Finally, it determines the type of the triangle by checking the lengths of its sides.