const fs = require('fs');

function addStrings(num1, num2) {
    let i = num1.length - 1, j = num2.length - 1, carry = 0;
    const res = [];
    while (i >= 0 || j >= 0 || carry > 0) {
        let sum = carry;
        if (i >= 0) sum += parseInt(num1[i--], 10);
        if (j >= 0) sum += parseInt(num2[j--], 10);
        res.push(sum % 10);
        carry = Math.floor(sum / 10);
    }
    return res.reverse().join('');
}

function main() {
    const input = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (input.length >= 2) {
        console.log(addStrings(input[0], input[1]));
    }
}

main();