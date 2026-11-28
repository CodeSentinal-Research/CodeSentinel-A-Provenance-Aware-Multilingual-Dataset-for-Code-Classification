const fs = require('fs');

function main() {
    const input = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (input.length >= 1) {
        const year = parseInt(input[0], 10);
        const isLeap = (year % 400 === 0) || (year % 4 === 0 && year % 100 !== 0);
        console.log(isLeap ? "Leap Year" : "Not a Leap Year");
    }
}

main();