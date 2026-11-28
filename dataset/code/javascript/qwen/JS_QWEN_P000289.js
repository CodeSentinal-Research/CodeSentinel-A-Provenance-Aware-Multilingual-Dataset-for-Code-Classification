const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const [s, kStr] = lines[0].split(/\s+/); // Assuming input format "string k" or separate lines? Problem says "String S and an integer K"
        // Re-reading problem: Input is String S and Integer K. Usually separate lines or same line.
        // Let's assume same line for simplicity based on previous patterns, or check length.
        // Actually, problem says "Input: A string S and an integer K".
        const k = parseInt(lines[1] || lines[0].split(' ')[1]);
        const str = lines[1] ? lines[0] : lines[0].split(' ')[0];
        
        let count = {}, l=0, maxF=0, maxL=0;
        for(let r=0; r<str.length; r++) {
            count[str[r]] = (count[str[r]]||0)+1;
            maxF = Math.max(maxF, count[str[r]]);
            while(r-l+1-maxF > k) {
                count[str[l]]--;
                l++;
            }
            maxL = Math.max(maxL, r-l+1);
        }
        console.log(maxL);
        rl.close();
    }
});
