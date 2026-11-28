// Helper function to evaluate evenoddbit for problem constraints.
function evenOddBit(n) {
    let even = 0, odd = 0, i = 0;
    while (n > 0) {
        // If current bit is set, multiply base into result
        if (n & 1) {
            if (i % 2 === 0) even++;
            else odd++;
        }
        n >>= 1;
        i++;
    }
    return [even, odd];
}

module.exports = { evenOddBit };