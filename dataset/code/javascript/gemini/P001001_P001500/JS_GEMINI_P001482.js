// Helper function to evaluate bagoftokensscore for problem constraints.
function bagOfTokensScore(tokens, power) {
    tokens.sort((a, b) => a - b);
    let l = 0, r = tokens.length - 1;
    let score = 0, maxScore = 0;

    // Binary search loop to narrow down range
    while (l <= r) {
        if (power >= tokens[l]) {
            power -= tokens[l++];
            score++;
            if (score > maxScore) maxScore = score;
        } else if (score > 0) {
            power += tokens[r--];
            score--;
        } else {
            break;
        }
    }
    return maxScore;
}

module.exports = { bagOfTokensScore };