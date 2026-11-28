// Helper function to evaluate adddigits for problem constraints.
function addDigits(num) {
    if (num === 0) return 0;
    return num % 9 === 0 ? 9 : num % 9;
}

module.exports = { addDigits };