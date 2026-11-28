const fs = require('fs');
function main() {
    const input = fs.readFileSync(0, 'utf-8');
    if (input) {
        const tokens = input.trim().split(/\s+/);
        const ops = tokens.filter(t => t === 'next()' || t === 'hasNext()');
        const nums = (input.match(/-?\d+/g) || []).map(Number);
        let idx = 0;
        for (const op of ops) {
            if (op === 'next()') {
                if (idx < nums.length) console.log(nums[idx++]);
            } else if (op === 'hasNext()') {
                console.log(idx < nums.length ? "true" : "false");
            }
        }
    }
}
main();