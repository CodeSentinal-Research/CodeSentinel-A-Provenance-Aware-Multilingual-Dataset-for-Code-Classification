const fs = require('fs');
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 1 && tokens[0] !== '') {
        const q = parseInt(tokens[0], 10);
        let idx = 1;
        const nums = new Set();
        for (let i = 0; i < q; i++) {
            const cmd = tokens[idx];
            if (cmd === 'addNum') {
                nums.add(parseInt(tokens[idx+1], 10));
                idx += 2;
            } else if (cmd === 'getIntervals') {
                const sorted = Array.from(nums).sort((a, b) => a - b);
                const intervals = [];
                for (const x of sorted) {
                    if (intervals.length > 0 && intervals[intervals.length - 1][1] + 1 === x) {
                        intervals[intervals.length - 1][1] = x;
                    } else {
                        intervals.push([x, x]);
                    }
                }
                console.log(intervals.map(([a, b]) => `[${a},${b}]`).join(' '));
                idx += 1;
            }
        }
    }
}
main();