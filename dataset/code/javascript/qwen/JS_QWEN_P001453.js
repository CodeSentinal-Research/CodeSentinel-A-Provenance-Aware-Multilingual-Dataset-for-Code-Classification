const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const s = input.trim();
    let maxLen = 1, currLen = 1, char = s[0];
    for (let i = 1; i < s.length; i++) {
        if (s[i] === s[i-1]) {
            currLen++;
            if (currLen > maxLen || (currLen === maxLen && s[i] < char)) {
                maxLen = currLen;
                char = s[i];
            }
        } else {
            currLen = 1;
        }
    }
    console.log(`${char} ${maxLen}`);
    rl.close();
});
