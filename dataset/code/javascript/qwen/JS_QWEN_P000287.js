const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const s = input.trim();
    let chars = s.split('');
    let vowels = ['a','e','i','o','u'];
    let l=0, r=chars.length-1;
    while(l<r) {
        while(l<r && !vowels.includes(chars[l].toLowerCase())) l++;
        while(l<r && !vowels.includes(chars[r].toLowerCase())) r--;
        [chars[l], chars[r]] = [chars[r], chars[l]];
        l++; r--;
    }
    console.log(chars.join(''));
    rl.close();
});
