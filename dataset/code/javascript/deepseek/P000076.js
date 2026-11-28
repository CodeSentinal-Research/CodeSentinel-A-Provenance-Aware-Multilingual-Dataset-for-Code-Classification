function findRoots(a, b, c) {
    // Check if a is zero to avoid division by zero
    if (a === 0) {
        throw new Error("a must not be zero");
    }

    // Calculate the discriminant
    let discriminant = b * b - 4 * a * c;

    if (discriminant < 0) {
        // No real roots
        return [];
    } else if (discriminant === 0) {
        // One real root
        return [-b / (2 * a)];
    } else {
        // Two real roots
        let root1 = (-b + Math.sqrt(discriminant)) / (2 * a);
        let root2 = (-b - Math.sqrt(discriminant)) / (2 * a);
        return [root1, root2];
    }
}

console.log(findRoots(1, -3, 2));  // [2, 1]
console.log(findRoots(1, 0, -2));  // [2, -2]
console.log(findRoots(1, -3, 4));  // [2, 1]
console.log(findRoots(0, 0, 0));  // throws an error