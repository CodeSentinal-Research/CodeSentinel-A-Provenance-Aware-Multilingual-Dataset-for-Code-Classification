const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length >= 2) {
        const s1 = lines[0];
        const s2 = lines[1];
        const n = parseInt(lines[2]);
        let pairs = [];
        for (let i = 3; i < 3 + n; i++) pairs.push(lines[i].split(/\s+/));
        
        // Union Find for transitive similarity
        let parent = {};
        function find(x) {
            if (!parent[x]) parent[x] = x;
            if (parent[x] !== x) parent[x] = find(parent[x]);
            return parent[x];
        }
        function union(x, y) {
            parent[find(x)] = find(y);
        }
        
        for (let [a, b] of pairs) union(a, b);
        
        let similar = true;
        if (s1.length !== s2.length) similar = false;
        else {
            for (let i = 0; i < s1.length; i++) {
                if (s1[i] !== s2[i] && find(s1[i]) !== find(s2[i])) {
                    similar = false;
                    break;
                }
            }
        }
        console.log(similar ? "YES" : "NO");
        rl.close();
    }
});
