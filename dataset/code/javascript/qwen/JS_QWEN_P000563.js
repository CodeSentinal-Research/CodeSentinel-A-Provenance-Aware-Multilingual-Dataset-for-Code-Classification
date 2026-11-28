const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === parseInt(lines[0])+3) {
        const begin = lines[0];
        const end = lines[1];
        const n = parseInt(lines[2]);
        let wordList = [];
        for(let i=3; i<3+n; i++) wordList.push(lines[i]);
        let set = new Set(wordList);
        if(!set.has(end)) { console.log(0); rl.close(); return; }
        let q = [[begin, 1]];
        let visited = new Set([begin]);
        while(q.length) {
            let [word, steps] = q.shift();
            if(word===end) { console.log(steps); rl.close(); return; }
            for(let i=0; i<word.length; i++) {
                for(let c=97; c<=122; c++) {
                    let next = word.substring(0,i) + String.fromCharCode(c) + word.substring(i+1);
                    if(set.has(next) && !visited.has(next)) {
                        visited.add(next);
                        q.push([next, steps+1]);
                    }
                }
            }
        }
        console.log(0);
        rl.close();
    }
});
