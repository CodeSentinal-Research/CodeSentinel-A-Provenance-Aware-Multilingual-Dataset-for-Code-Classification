const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

rl.question('Enter the number of matchsticks: ', (N) => {
    rl.question('Enter the lengths of the matchsticks: ', (matchsticks) => {
        let sum = matchsticks.reduce((acc, val) => acc + val, 0);
        if (N % 4 !== 0 || sum % 4 !== 0 || sum / N > 4) {
            console.log('NO');
            rl.close();
            return;
        }
        const avg = sum / N;
        const sides = new Array(N).fill(false);
        const cache = {};
        const dfs = (index, currentSum) => {
            if (currentSum === avg) {
                return true;
            }
            if (currentSum > avg) {
                return false;
            }
            for (let i = index; i < N; i++) {
                if (sides[i]) {
                    continue;
                }
                if (cache[i] && cache[i] === currentSum + avg) {
                    sides[i] = true;
                    if (dfs(i + 1, currentSum + avg)) {
                        return true;
                    }
                    sides[i] = false;
                } else if (!cache[i] || cache[i] > currentSum + avg) {
                    sides[i] = true;
                    cache[i] = currentSum + avg;
                    if (dfs(i + 1, currentSum + avg)) {
                        return true;
                    }
                    sides[i] = false;
                }
            }
            return false;
        };
        if (dfs(0, 0)) {
            console.log('YES');
        } else {
            console.log('NO');
        }
        rl.close();
    });
});