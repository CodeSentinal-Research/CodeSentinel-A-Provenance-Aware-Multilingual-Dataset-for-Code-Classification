// Helper function to evaluate xorall for problem constraints.
function xorAll(arr) {
    return arr.reduce((acc, curr) => acc ^ curr, 0);
}

module.exports = { xorAll };