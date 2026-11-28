// Helper function to evaluate isharshad for problem constraints.
function isHarshad(n) {
    if (n <= 0) return false;
    let sum = 0, temp = n;
    while (temp > 0) {
        sum += temp % 10;
        temp = Math.floor(temp / 10);
    }
    return n % sum === 0;
}

module.exports = { isHarshad };