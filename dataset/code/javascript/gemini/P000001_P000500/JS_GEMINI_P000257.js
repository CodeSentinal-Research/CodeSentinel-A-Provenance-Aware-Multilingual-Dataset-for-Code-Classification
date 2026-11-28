const fs = require('fs');
function main() {
    const input = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (input.length >= 2) {
        const s1 = input[0].split('').sort().join('');
        const s2 = input[1].split('').sort().join('');
        console.log(s1 === s2 ? "Anagram" : "Not Anagram");
    }
}
main();