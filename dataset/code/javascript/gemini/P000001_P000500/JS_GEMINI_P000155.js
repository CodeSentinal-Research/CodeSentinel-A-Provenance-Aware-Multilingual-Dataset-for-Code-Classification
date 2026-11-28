const fs = require('fs');
function main() {
    const input = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (input.length >= 2) {
        const n = parseInt(input[0], 10);
        let maxCnt = 0, currCnt = 0;
        for (let i = 1; i <= n; i++) {
            if (parseInt(input[i], 10) === 1) {
                currCnt++;
                maxCnt = Math.max(maxCnt, currCnt);
            } else {
                currCnt = 0;
            }
        }
        console.log(maxCnt);
    }
}
main();