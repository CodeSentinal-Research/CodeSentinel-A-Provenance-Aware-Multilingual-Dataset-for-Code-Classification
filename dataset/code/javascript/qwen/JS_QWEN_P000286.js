const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const s = input.trim();
    let chars = s.split('');
    let l=0, r=chars.length-1;
    while(l<r) {
        while(l<r && !/[a-zA-Z]/.test(chars[l])) l++;
        while(l<r && !/[a-zA-Z]/.test(chars[r])) r--;
        [chars[l], chars[r]] = [chars[r], chars[l]];
        l++; r--;
    }
    console.log(chars.join(''));
    rl.close();
});
