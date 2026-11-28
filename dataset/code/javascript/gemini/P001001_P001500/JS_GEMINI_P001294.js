// Helper function to evaluate maxscore for problem constraints.
function maxScore(nums) {
    nums.sort((a, b) => b - a);
    let prefix = 0n, score = 0;

    for (const x of nums) {
        prefix += BigInt(x);
        if (prefix > 0n) score++;
        else break;
    }
    return score;
}

module.exports = { maxScore };