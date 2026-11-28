// Helper function to evaluate isdivisibleby9 for problem constraints.
function isDivisibleBy9(s) {
    let sum = 0;
    for (const c of s) {
        if (/\d/.test(c)) sum += parseInt(c, 10);
    }
    return sum % 9 === 0;
}

module.exports = { isDivisibleBy9 };