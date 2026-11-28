const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === parseInt(lines[0])+2) {
        const n = parseInt(lines[0]);
        const minRating = parseFloat(lines[1]);
        let found = false;
        for(let i=2; i<2+n; i++) {
            let [rname, rating] = lines[i].split(/\s+/);
            if(parseFloat(rating) >= minRating) { console.log(rname); found=true; }
        }
        if(!found) console.log("No High Rated Restaurants");
        rl.close();
    }
});
