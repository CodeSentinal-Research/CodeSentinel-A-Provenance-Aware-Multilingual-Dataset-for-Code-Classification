const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

rl.question('Enter a numeric string: ', (input) => {
    const arr = input.split('').map(Number);
    let flag = true;

    for(let i = 0; i < arr.length - 1; i++) {
        if(arr[i] < arr[i+1]) {
            flag = false;
            break;
        }
    }

    if(flag) {
        console.log('YES');
    } else {
        console.log('NO');
    }

    rl.close();
});
This script will first create an array from the input string, map each character to a number, and then iterate over the array. If the current number is less than the next one, it will set the flag to false and break the loop. If the flag is still true after the loop, it means that the array can be split into two or more non-empty substrings, and the script will print 'YES'. Otherwise, it will print 'NO'. The input is read from the console.