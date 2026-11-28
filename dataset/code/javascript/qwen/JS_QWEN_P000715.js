const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const arr = lines[1].split(/\s+/).map(Number).sort((a,b)=>a-b);
        let res = [];
        function subsets(i, curr) {
            if (i === n) {
                res.push(curr.join(" "));
                return;
            }
            subsets(i + 1, curr);
            if (i > 0 && arr[i] === arr[i-1] && !curr.includes(arr[i-1])) {
                 // Simplified duplicate check for brevity in recursion
            }
            subsets(i + 1, [...curr, arr[i]]);
        }
        // Better approach for unique subsets
        res = [];
        function uniqueSubsets(idx, path) {
            res.push(path.slice());
            for(let i=idx; i<n; i++) {
                if(i>idx && arr[i]==arr[i-1]) continue;
                path.push(arr[i]);
                uniqueSubsets(i+1, path);
                path.pop();
            }
        }
        uniqueSubsets(0, []);
        console.log(res.map(x=>x.join(" ")).join("\n"));
        rl.close();
    }
});
