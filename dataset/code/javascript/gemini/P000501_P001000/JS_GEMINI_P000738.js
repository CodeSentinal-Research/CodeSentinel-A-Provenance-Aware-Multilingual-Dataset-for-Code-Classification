const fs = require('fs');
function countArrangements(n) {
    const used = new Array(n + 1).fill(false);
    function backtrack(pos) {
        if (pos > n) return 1;
        let count = 0;
        for (let i = 1; i <= n; i++) {
            if (!used[i] && (i % pos === 0 || pos % i === 0)) {
                used[i] = true;
                count += backtrack(pos + 1);
                used[i] = false;
            }
        }
        return count;
    }
    return backtrack(1);
}
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 1 && tokens[0] !== '') {
        console.log(countArrangements(parseInt(tokens[0], 10)));
    }
}
main();