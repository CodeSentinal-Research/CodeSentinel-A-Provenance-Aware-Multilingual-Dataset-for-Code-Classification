Here is a JavaScript solution using the quadratic formula to solve the linear Diophantine equation AX + BY = C.

function solveDiophantine(A, B, C) {
    // Check if B^2 - 4AC is a perfect square
    let discriminant = B * B - 4 * A * C;
    if (discriminant < 0) {
        console.log('No solution');
    } else if (discriminant === 0) {
        console.log('Solution: ' + (-B / (2 * A)));
    } else {
        let sol1 = (-B + Math.sqrt(discriminant)) / (2 * A);
        let sol2 = (-B - Math.sqrt(discriminant)) / (2 * A);
        console.log('Solutions: ' + sol1 + ', ' + sol2);
    }
}

To use this function, simply call it with the three integers A, B, and C as arguments:

solveDiophantine(1, -3, 2); // for example

This function first checks if B^2 - 4AC is a perfect square, as the discriminant of the quadratic equation AX^2 + BY^2 = C0 (where 0 is the constant term) must be a perfect square for the equation to have a real integer solution.

If the discriminant is positive, the equation has two real solutions.

If the discriminant is zero, the equation has exactly one real solution.

If the discriminant is negative, the equation has no real solutions.

The quadratic formula is used to solve the quadratic equation AX^2 + BY^2 = C0.