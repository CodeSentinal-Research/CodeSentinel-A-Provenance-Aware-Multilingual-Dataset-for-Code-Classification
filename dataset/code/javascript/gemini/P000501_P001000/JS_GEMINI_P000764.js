const fs = require('fs');
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 2 && tokens[0] !== '') {
        const s = tokens[0];
        let k = BigInt(tokens[1]);
        let size = 0n;
        for (const c of s) {
            if (/\d/.test(c)) size *= BigInt(c);
            else size += 1n;
        }
        for (let i = s.length - 1; i >= 0; i--) {
            const c = s[i];
            k %= size;
            if (k === 0n && /[a-zA-Z]/.test(c)) {
                console.log(c);
                return;
            }
            if (/\d/.test(c)) size /= BigInt(c);
            else size -= 1n;
        }
    }
}
main();