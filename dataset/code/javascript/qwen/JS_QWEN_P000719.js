const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const s = input.trim();
    let res = [];
    function restore(ip, parts, start) {
        if (parts.length === 4 && start === s.length) {
            res.push(parts.join("."));
            return;
        }
        for (let len = 1; len <= 3; len++) {
            if (start + len > s.length) break;
            let segment = s.substring(start, start + len);
            if ((segment.length > 1 && segment[0] === '0') || parseInt(segment) > 255) continue;
            restore(s, [...parts, segment], start + len);
        }
    }
    restore(s, [], 0);
    console.log(res.join("\n"));
    rl.close();
});
