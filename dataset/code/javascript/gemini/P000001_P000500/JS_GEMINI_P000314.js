const fs = require('fs');

function convertToTitle(columnNumber) {
    let res = [];
    let n = BigInt(columnNumber);
    while (n > 0n) {
        n -= 1n;
        res.push(String.fromCharCode(65 + Number(n % 26n)));
        n /= 26n;
    }
    return res.reverse().join('');
}

function main() {
    const input = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (input.length >= 1 && input[0] !== '') {
        console.log(convertToTitle(input[0]));
    }
}

main();