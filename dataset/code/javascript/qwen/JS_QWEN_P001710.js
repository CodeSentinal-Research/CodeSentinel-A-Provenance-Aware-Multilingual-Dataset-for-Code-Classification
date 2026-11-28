const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const s = input.trim();
    let res = [];
    function permute(str, l, r) {
        if (l === r) {
            res.push(str);
            return;
        }
        for (let i = l; i <= r; i++) {
            str = str.split('');
            [str[l], str[i]] = [str[i], str[l]];
            str = str.join('');
            permute(str, l + 1, r);
            str = str.split('');
            [str[l], str[i]] = [str[i], str[l]];
            str = str.join('');
        }
    }
    permute(s, 0, s.length - 1);
    console.log([...new Set(res)].sort().join("\n"));
    rl.close();
});
