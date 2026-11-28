const fs = require('fs');

function main() {
    const lines = fs.readFileSync(0, 'utf-8').trim().split('\n');
    if (lines.length >= 2) {
        const s1 = lines[0].trim().split(/\s+/).join('');
        const s2 = lines[1].trim().split(/\s+/).join('');
        console.log(s1 === s2 ? "Yes" : "No");
    }
}

main();