const fs = require('fs');
function main() {
    const lines = fs.readFileSync(0, 'utf-8').split(/\r?\n/);
    if (lines.length >= 1 && lines[0].trim() !== '') {
        const n = parseInt(lines[0].trim(), 10);
        const records = lines.slice(1, n + 1);
        const keyword = lines[n + 1].trim();
        records.filter(r => r.includes(keyword)).forEach(r => console.log(r));
    }
}
main();