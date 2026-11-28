const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

rl.question('Enter three integers: ', (A, B, C) => {
    let res = '';

    while (A--) {
        if (res[res.length - 1] !== 'a') res += 'a';
        else if (res[res.length - 1] !== 'b') res += 'b';
        else if (res[res.length - 1] !== 'c') res += 'c';
    }

    console.log(res);

    rl.close();
});