const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === parseInt(lines[0])+3) {
        const n = parseInt(lines[0]);
        const author = lines[1];
        const genre = lines[2];
        let found = false;
        for(let i=3; i<3+n; i++) {
            let [btitle, bauthor, bgenre] = lines[i].split(/\s+/);
            if(bauthor === author && bgenre === genre) { console.log(btitle); found=true; }
        }
        if(!found) console.log("No Books Found");
        rl.close();
    }
});
