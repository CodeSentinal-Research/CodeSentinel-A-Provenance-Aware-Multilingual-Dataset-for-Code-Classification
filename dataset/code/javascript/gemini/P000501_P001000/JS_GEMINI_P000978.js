// Helper function to evaluate triangletype for problem constraints.
function triangleType(x1, y1, x2, y2, x3, y3) {
    if ((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) === 0) {
        return "Not a Triangle";
    }
    const d1 = (x1 - x2) ** 2 + (y1 - y2) ** 2;
    const d2 = (x2 - x3) ** 2 + (y2 - y3) ** 2;
    const d3 = (x3 - x1) ** 2 + (y3 - y1) ** 2;

    if (d1 === d2 && d2 === d3) return "Equilateral";
    if (d1 === d2 || d2 === d3 || d3 === d1) return "Isosceles";
    return "Scalene";
}

module.exports = { triangleType };