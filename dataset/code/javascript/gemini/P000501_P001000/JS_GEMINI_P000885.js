// Helper function to evaluate isarmstrong for problem constraints.
function isArmstrong(n) {
    const s = n.toString();
    const k = s.length;
    let sum = 0;
    for (const ch of s) {
        sum += Math.pow(parseInt(ch, 10), k);
    }
    return sum === n;
}

module.exports = { isArmstrong };