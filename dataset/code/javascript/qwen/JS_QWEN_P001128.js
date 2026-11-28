const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length >= 2) {
        const n = parseInt(lines[0]);
        let accounts = [];
        for(let i=1; i<=n; i++) accounts.push(lines[i].split(/\s+/));
        
        let parent = new Array(n).fill(0).map((_, i) => i);
        function find(u) {
            if(parent[u] !== u) parent[u] = find(parent[u]);
            return parent[u];
        }
        function union(u, v) {
            let pu = find(u), pv = find(v);
            if(pu !== pv) parent[pu] = pv;
        }
        
        let emailToIndex = {};
        for(let i=0; i<n; i++) {
            let name = accounts[i][0];
            for(let j=1; j<accounts[i].length; j++) {
                let email = accounts[i][j];
                if(emailToIndex[email] !== undefined) {
                    union(i, emailToIndex[email]);
                } else {
                    emailToIndex[email] = i;
                }
            }
        }
        
        let groups = {};
        for(let email in emailToIndex) {
            let root = find(emailToIndex[email]);
            if(!groups[root]) groups[root] = {name: accounts[root][0], emails: []};
            groups[root].emails.push(email);
        }
        
        let res = [];
        for(let k in groups) {
            groups[k].emails.sort();
            res.push([groups[k].name, ...groups[k].emails].join(" "));
        }
        console.log(res.join("\n"));
        rl.close();
    }
});
