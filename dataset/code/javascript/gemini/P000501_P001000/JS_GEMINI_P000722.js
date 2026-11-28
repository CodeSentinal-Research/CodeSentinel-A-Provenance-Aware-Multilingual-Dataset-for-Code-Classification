const fs = require('fs');
function canMakeSquare(matchsticks) {
    const total = matchsticks.reduce((a, b) => a + b, 0);
    if (total % 4 !== 0 || matchsticks.length < 4) return false;
    const side = total / 4;
    matchsticks.sort((a, b) => b - a);
    if (matchsticks[0] > side) return false;
    const sides = [0, 0, 0, 0];
    function backtrack(idx) {
        if (idx === matchsticks.length) return true;
        for (let i = 0; i < 4; i++) {
            if (sides[i] + matchsticks[idx] <= side) {
                sides[i] += matchsticks[idx];
                if (backtrack(idx + 1)) return true;
                sides[i] -= matchsticks[idx];
            }
            if (sides[i] === 0) break;
        }
        return false;
    }
    return backtrack(0);
}
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 1 && tokens[0] !== '') {
        const n = parseInt(tokens[0], 10);
        const matchsticks = tokens.slice(1, 1 + n).map(Number);
        console.log(canMakeSquare(matchsticks) ? "true" : "false");
    }
}
main();