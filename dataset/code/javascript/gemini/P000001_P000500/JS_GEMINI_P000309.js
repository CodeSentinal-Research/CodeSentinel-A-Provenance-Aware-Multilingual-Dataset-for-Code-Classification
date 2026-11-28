const fs = require('fs');

function multiply(num1, num2) {
    if (num1 === '0' || num2 === '0') return '0';
    const m = num1.length, n = num2.length;
    const pos = new Array(m + n).fill(0);
    for (let i = m - 1; i >= 0; i--) {
        for (let j = n - 1; j >= 0; j--) {
            const mul = parseInt(num1[i], 10) * parseInt(num2[j], 10);
            const p1 = i + j, p2 = i + j + 1;
            const sum = mul + pos[p2];
            pos[p2] = sum % 10;
            pos[p1] += Math.floor(sum / 10);
        }
    }
    let idx = 0;
    while (idx < pos.length && pos[idx] === 0) idx++;
    return idx < pos.length ? pos.slice(idx).join('') : '0';
}

function main() {
    const input = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (input.length >= 2) {
        console.log(multiply(input[0], input[1]));
    }
}

main();