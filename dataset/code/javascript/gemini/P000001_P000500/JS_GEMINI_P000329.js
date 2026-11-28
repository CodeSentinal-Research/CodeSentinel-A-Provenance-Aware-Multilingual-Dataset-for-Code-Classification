const fs = require('fs');

function main() {
    const input = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (input.length >= 2) {
        let code = 0;
        for (const c of input[0] + input[1]) {
            code ^= c.charCodeAt(0);
        }
        console.log(String.fromCharCode(code));
    }
}

main();