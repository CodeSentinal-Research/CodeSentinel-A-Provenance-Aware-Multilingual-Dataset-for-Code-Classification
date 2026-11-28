// Helper function to evaluate findcomplement for problem constraints.
function findComplement(num) {
    const mask = (1 << (32 - Math.clz32(num))) - 1;
    return num ^ mask;
}

module.exports = { findComplement };