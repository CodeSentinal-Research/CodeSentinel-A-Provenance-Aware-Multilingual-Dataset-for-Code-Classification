const fs = require('fs');

function isValidNumber(s) {
    const regex = /^[+-]?(\d+(\.\d*)?|\.\d+)([eE][+-]?\d+)?$/;
    return regex.test(s.trim());
}

function main() {
    const input = fs.readFileSync(0, 'utf-8').trim();
    if (input.length > 0) {
        console.log(isValidNumber(input) ? "Valid" : "Invalid");
    }
}

main();