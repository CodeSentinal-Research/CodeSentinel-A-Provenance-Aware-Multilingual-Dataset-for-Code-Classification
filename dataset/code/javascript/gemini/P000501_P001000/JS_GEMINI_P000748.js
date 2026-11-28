const fs = require('fs');
function diceRolls(target, cur) {
    if (target === 0) {
        console.log(cur.join(' '));
        return;
    }
    for (let i = 1; i <= 6 && i <= target; i++) {
        diceRolls(target - i, [...cur, i]);
    }
}
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 1 && tokens[0] !== '') {
        diceRolls(parseInt(tokens[0], 10), []);
    }
}
main();