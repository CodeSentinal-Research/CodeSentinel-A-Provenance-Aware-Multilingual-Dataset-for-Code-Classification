const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length >= 2) {
        const n = parseInt(lines[0]);
        let words = [];
        for(let i=1; i<=n; i++) words.push(lines[i]);
        
        // Build graph of characters
        let adj = Array.from({length: 26}, () => []);
        let inDegree = new Array(26).fill(0);
        let nodes = new Set();
        
        for(let i=0; i<n-1; i++) {
            let w1 = words[i], w2 = words[i+1];
            let minLen = Math.min(w1.length, w2.length);
            let found = false;
            for(let j=0; j<minLen; j++) {
                if(w1[j] !== w2[j]) {
                    let u = w1.charCodeAt(j)-97, v = w2.charCodeAt(j)-97;
                    adj[u].push(v);
                    inDegree[v]++;
                    nodes.add(u); nodes.add(v);
                    found = true;
                    break;
                }
            }
            if(!found && w1.length > w2.length) { console.log("IMPOSSIBLE"); rl.close(); return; }
            for(let c of w1) nodes.add(c.charCodeAt(0)-97);
            for(let c of w2) nodes.add(c.charCodeAt(0)-97);
        }
        
        let queue = [];
        for(let i=0; i<26; i++) if(inDegree[i]===0 && nodes.has(i)) queue.push(i);
        
        let order = [];
        while(queue.length > 0) {
            let u = queue.shift();
            order.push(String.fromCharCode(u+97));
            for(let v of adj[u]) {
                inDegree[v]--;
                if(inDegree[v]===0) queue.push(v);
            }
        }
        
        // Add isolated nodes
        for(let i=0; i<26; i++) if(nodes.has(i) && !order.includes(String.fromCharCode(i+97))) order.push(String.fromCharCode(i+97));
        
        console.log(order.length === nodes.size ? order.join("") : "IMPOSSIBLE");
        rl.close();
    }
});
