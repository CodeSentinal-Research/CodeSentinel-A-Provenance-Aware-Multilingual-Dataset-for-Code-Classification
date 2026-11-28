const fs = require('fs');

function addBinary(a, b) {
    let i = a.length - 1, j = b.length - 1, carry = 0;
    const res = [];
    while (i >= 0 || j >= 0 || carry > 0) {
        let sum = carry;
        if (i >= 0) sum += parseInt(a[i--], 10);
        if (j >= 0) sum += parseInt(b[j--], 10);
        res.push(sum % 2);
        carry = Math.floor(sum / 2);
    }
    return res.reverse().join('');
}

function main() {
    const input = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (input.length >= 2) {
        console.log(addBinary(input[0], input[1]));
    }
}

main();