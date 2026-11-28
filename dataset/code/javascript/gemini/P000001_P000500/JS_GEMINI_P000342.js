const fs = require('fs');

function main() {
    const input = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (input.length >= 1 && input[0] !== '') {
        const s = input[0].split('');
        for (let i = 1; i < s.length; i += 2) {
            s[i] = String.fromCharCode(s[i - 1].charCodeAt(0) + parseInt(s[i], 10));
        }
        console.log(s.join(''));
    }
}

main();