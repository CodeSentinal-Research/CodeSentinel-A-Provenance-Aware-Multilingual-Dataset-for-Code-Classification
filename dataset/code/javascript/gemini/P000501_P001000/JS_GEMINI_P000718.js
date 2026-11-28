const fs = require('fs');
function grayCode(n) {
    if (n === 0) return ["0"];
    if (n === 1) return ["0", "1"];
    const prev = grayCode(n - 1);
    const res = [];
    for (const s of prev) res.push("0" + s);
    for (let i = prev.length - 1; i >= 0; i--) res.push("1" + prev[i]);
    return res;
}
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 1 && tokens[0] !== '') {
        for (const s of grayCode(parseInt(tokens[0], 10))) console.log(s);
    }
}
main();