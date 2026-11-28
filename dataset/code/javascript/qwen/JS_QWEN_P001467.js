const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const s = input.trim();
    let arr = s.split('');
    let vowels = new Set(['a','e','i','o','u','A','E','I','O','U']);
    let l = 0, r = arr.length - 1;
    while (l < r) {
        while (l < r && !vowels.has(arr[l])) l++;
        while (l < r && !vowels.has(arr[r])) r--;
        [arr[l], arr[r]] = [arr[r], arr[l]];
        l++; r--;
    }
    console.log(arr.join(''));
    rl.close();
});
