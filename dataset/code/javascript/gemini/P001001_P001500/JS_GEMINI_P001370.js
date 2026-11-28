// Helper function to evaluate maximumswap for problem constraints.
function maximumSwap(num) {
    const digits = String(num).split('');
    const last = {};
    digits.forEach((d, i) => { last[d] = i; });

    for (let i = 0; i < digits.length; i++) {
        for (let d = 9; d > Number(digits[i]); d--) {
            if (last[d] > i) {
                [digits[i], digits[last[d]]] = [digits[last[d]], digits[i]];
                return Number(digits.join(''));
            }
        }
    }
    return num;
}

module.exports = { maximumSwap };