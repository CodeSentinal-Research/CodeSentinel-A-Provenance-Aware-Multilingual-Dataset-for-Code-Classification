const fs = require('fs');

function checkRecord(s) {
    let aCount = 0;
    for (let i = 0; i < s.length; i++) {
        if (s[i] === 'A') aCount++;
    }
    return aCount < 2 && !s.includes('LLL');
}

function main() {
    const input = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (input.length >= 1 && input[0] !== '') {
        console.log(checkRecord(input[0]) ? "Yes" : "No");
    }
}

main();