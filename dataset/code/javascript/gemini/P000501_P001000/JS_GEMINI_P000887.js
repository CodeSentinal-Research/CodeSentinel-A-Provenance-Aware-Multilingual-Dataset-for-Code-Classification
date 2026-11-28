// Helper function to evaluate isneon for problem constraints.
function isNeon(n) {
    let sq = n * n;
    let sum = 0;
    while (sq > 0) {
        sum += sq % 10;
        sq = Math.floor(sq / 10);
    }
    return sum === n;
}

module.exports = { isNeon };