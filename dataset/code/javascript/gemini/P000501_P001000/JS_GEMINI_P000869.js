// Helper function to evaluate divide for problem constraints.
function divide(dividend, divisor) {
    if (dividend === -2147483648 && divisor === -1) return 2147483647;
    const sign = (dividend < 0) ^ (divisor < 0) ? -1 : 1;
    let dvd = Math.abs(dividend);
    let dvs = Math.abs(divisor);
    let ans = 0;
    while (dvd >= dvs) {
        let temp = dvs;
        let m = 1;
        while (temp * 2 <= dvd) {
            temp *= 2;
            m *= 2;
        }
        dvd -= temp;
        ans += m;
    }
    return sign * ans;
}

module.exports = { divide };