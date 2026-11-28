const fs = require('fs');

function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 1 && tokens[0] !== '') {
        const n = parseInt(tokens[0], 10);
        const employees = [];
        let idx = 1;
        for (let i = 0; i < n; i++) {
            employees.push({name: tokens[idx], sal: parseFloat(tokens[idx + 1])});
            idx += 2;
        }
        const minSal = parseFloat(tokens[idx]);
        const maxSal = parseFloat(tokens[idx + 1]);
        employees.filter(e => e.sal >= minSal && e.sal <= maxSal).forEach(e => console.log(e.name));
    }
}

main();