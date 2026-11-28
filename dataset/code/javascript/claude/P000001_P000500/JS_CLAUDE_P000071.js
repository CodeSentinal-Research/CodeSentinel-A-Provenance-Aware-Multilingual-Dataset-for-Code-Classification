function typeOfTriangle(a, b, c) {
    if (!(a + b > c && a + c > b && b + c > a)) return "Invalid";
    if (a === b && b === c) return "Equilateral";
    if (a === b || b === c || a === c) return "Isosceles";
    return "Scalene";
}

module.exports = { typeOfTriangle };
