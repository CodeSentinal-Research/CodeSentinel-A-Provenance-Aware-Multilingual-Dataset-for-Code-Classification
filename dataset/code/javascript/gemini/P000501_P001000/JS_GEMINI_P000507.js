const fs = require('fs');
function main() {
    const s = fs.readFileSync(0, 'utf-8').trim();
    if (s) {
        const nodes = s.split(',');
        let slots = 1;
        for (const node of nodes) {
            slots--;
            if (slots < 0) { console.log("false"); return; }
            if (node !== '#') slots += 2;
        }
        console.log(slots === 0 ? "true" : "false");
    }
}
main();