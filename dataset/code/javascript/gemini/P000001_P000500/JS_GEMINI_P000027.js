const fs = require('fs');
function main() {
    const input = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (input.length >= 1) {
        const s = input[0];
        const rev = s.split('').reverse().join('');
        console.log(s === rev ? "Palindrome" : "Not Palindrome");
    }
}
main();