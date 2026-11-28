const fs = require('fs');

function repeatedSubstringPattern(s) {
    const ss = s + s;
    return ss.slice(1, -1).includes(s);
}

function main() {
    const input = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (input.length >= 1 && input[0] !== '') {
        console.log(repeatedSubstringPattern(input[0]) ? "Yes" : "No");
    }
}

main();