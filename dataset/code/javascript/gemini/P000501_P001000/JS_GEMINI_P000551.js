const fs = require('fs');
function main() {
    const token = fs.readFileSync(0, 'utf-8').trim();
    if (token) {
        const n = parseInt(token, 10);
        const q = ["1"];
        const res = [];
        for (let i = 1; i <= n; i++) {
            const cur = q.shift();
            res.push(cur);
            q.push(cur + "0");
            q.push(cur + "1");
        }
        console.log(res.join(' '));
    }
}
main();