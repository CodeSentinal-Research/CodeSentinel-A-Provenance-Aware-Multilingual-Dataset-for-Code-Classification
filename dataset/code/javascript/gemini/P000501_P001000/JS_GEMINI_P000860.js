// Helper function to evaluate bitwisecomplement for problem constraints.
function bitwiseComplement(n) {
    if (n === 0) return 1;
    const mask = (1 << (32 - Math.clz32(n))) - 1;
    return n ^ mask;
}

module.exports = { bitwiseComplement };