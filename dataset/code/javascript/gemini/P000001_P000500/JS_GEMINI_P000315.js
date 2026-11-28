const fs = require('fs');

function titleToNumber(columnTitle) {
    let res = 0;
    for (let i = 0; i < columnTitle.length; i++) {
        res = res * 26 + (columnTitle.charCodeAt(i) - 65 + 1);
    }
    return res;
}

function main() {
    const input = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (input.length >= 1 && input[0] !== '') {
        console.log(titleToNumber(input[0]));
    }
}

main();