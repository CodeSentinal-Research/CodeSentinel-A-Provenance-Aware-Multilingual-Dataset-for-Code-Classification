// Helper function to evaluate isdivisibleby3 for problem constraints.
function isDivisibleBy3(s) {
    let sum = 0;
    for (const c of s) {
        if (/\d/.test(c)) sum += parseInt(c, 10);
    }
    return sum % 3 === 0;
}

module.exports = { isDivisibleBy3 };