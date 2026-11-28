// Helper function to evaluate isdivisibleby11 for problem constraints.
function isDivisibleBy11(s) {
    let oddSum = 0, evenSum = 0;
    for (let i = 0; i < s.length; i++) {
        if (i % 2 === 0) oddSum += parseInt(s[i], 10);
        else evenSum += parseInt(s[i], 10);
    }
    return Math.abs(oddSum - evenSum) % 11 === 0;
}

module.exports = { isDivisibleBy11 };