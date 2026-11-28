const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const arr = lines[1].split(/\s+/).map(Number);
        let low=0, mid=0, high=n-1;
        while(mid <= high) {
            if(arr[mid]===0) { [arr[low], arr[mid]] = [arr[mid], arr[low]]; low++; mid++; }
            else if(arr[mid]===1) mid++;
            else { [arr[mid], arr[high]] = [arr[high], arr[mid]]; high--; }
        }
        console.log(arr.join(" "));
        rl.close();
    }
});
