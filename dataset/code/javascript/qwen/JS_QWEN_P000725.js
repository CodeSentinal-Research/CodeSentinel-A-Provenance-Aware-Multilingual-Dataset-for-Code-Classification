const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const s = input.trim();
    function canSplit(s, prevNum) {
        if (s.length === 0) return true;
        for (let i = 1; i <= s.length; i++) {
            let numStr = s.substring(0, i);
            if (numStr.length > 1 && numStr[0] === '0') break;
            let num = parseInt(numStr);
            if (prevNum !== null && num !== prevNum - 1) continue;
            if (canSplit(s.substring(i), num)) return true;
        }
        return false;
    }
    // Try all first numbers
    let found = false;
    for (let i = 1; i < s.length; i++) {
        let first = s.substring(0, i);
        if (first.length > 1 && first[0] === '0') break;
        if (canSplit(s.substring(i), parseInt(first) - 1)) { found = true; break; }
    }
    console.log(found ? "true" : "false");
    rl.close();
});
