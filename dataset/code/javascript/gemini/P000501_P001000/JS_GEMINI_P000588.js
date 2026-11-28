const fs = require('fs');
function main() {
    const content = fs.readFileSync(0, 'utf-8').trim();
    if (content) console.log(content.split(/\s+/).join(' '));
}
main();