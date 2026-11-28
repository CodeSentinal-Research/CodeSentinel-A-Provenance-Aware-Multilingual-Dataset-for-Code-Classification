// Helper function to evaluate graycode for problem constraints.
function grayCode(n) {
    const res = [];
    const total = 1 << n;
    for (let i = 0; i < total; i++) {
        res.push(i ^ (i >> 1));
    }
    return res;
}

module.exports = { grayCode };