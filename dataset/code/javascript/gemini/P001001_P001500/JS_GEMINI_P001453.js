// Calculates modular exponentiation (base^exp % mod) efficiently.
function maxPower(s) {
    let maxRun = 1, curRun = 1;
    for (let i = 1; i < s.length; i++) {
        if (s[i] === s[i - 1]) {
            curRun++;
            if (curRun > maxRun) maxRun = curRun;
        } else {
            curRun = 1;
        }
    }
    return maxRun;
}

module.exports = { maxPower };