const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const expr = input.trim();
    let memo = {};
    function countWays(expr, isTrue) {
        if (expr.length === 1) {
            return isTrue ? (expr === 'T' ? 1 : 0) : (expr === 'F' ? 1 : 0);
        }
        let key = `${expr},${isTrue}`;
        if (memo[key] !== undefined) return memo[key];
        let ways = 0;
        for (let i = 1; i < expr.length; i += 2) {
            let op = expr[i];
            let leftT = countWays(expr.substring(0, i), true);
            let leftF = countWays(expr.substring(0, i), false);
            let rightT = countWays(expr.substring(i + 1), true);
            let rightF = countWays(expr.substring(i + 1), false);
            let total = (leftT + leftF) * (rightT + rightF);
            let trueWays = 0;
            if (op === '&') trueWays = leftT * rightT;
            else if (op === '|') trueWays = leftT * rightT + leftT * rightF + leftF * rightT;
            else if (op === '^') trueWays = leftT * rightF + leftF * rightT;
            ways += isTrue ? trueWays : total - trueWays;
        }
        memo[key] = ways;
        return ways;
    }
    console.log(countWays(expr, true));
    rl.close();
});
