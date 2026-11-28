const fs = require('fs');
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 1 && tokens[0] !== '') {
        const n = parseInt(tokens[0], 10);
        const h = tokens.slice(1, 1 + n).map(BigInt);
        let maxSum = 0n;
        for (let peak = 0; peak < n; peak++) {
            let currSum = h[peak], cur = h[peak];
            for (let i = peak - 1; i >= 0; i--) {
                if (h[i] < cur) cur = h[i];
                currSum += cur;
            }
            cur = h[peak];
            for (let i = peak + 1; i < n; i++) {
                if (h[i] < cur) cur = h[i];
                currSum += cur;
            }
            if (currSum > maxSum) maxSum = currSum;
        }
        console.log(maxSum.toString());
    }
}
main();