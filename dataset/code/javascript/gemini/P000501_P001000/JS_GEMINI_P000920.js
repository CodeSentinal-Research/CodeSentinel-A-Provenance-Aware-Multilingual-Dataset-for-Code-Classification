// Helper function to evaluate minmaxdigit for problem constraints.
function minMaxDigit(n) {
    const digits = Math.abs(n).toString().split('').map(Number);
    return [Math.min(...digits), Math.max(...digits)];
}

module.exports = { minMaxDigit };