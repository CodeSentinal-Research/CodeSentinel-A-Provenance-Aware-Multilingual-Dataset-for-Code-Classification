Here's the JavaScript code:

const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let testCases = [];

rl.on('line', function(line) {
    testCases.push(line);
}).on('close', function() {
    for(let i = 0; i < testCases.length; i++) {
        let [str, k] = testCases[i].split(' ');
        k = parseInt(k);
        console.log(findMaxLen(str, k));
    }
    rl.close();
});

function findMaxLen(str, k) {
    let maxLen = 1;
    let curLen = 1;
    for(let i = 1; i < str.length; i++) {
        if (str[i] === str[i-1]) {
            curLen++;
        } else {
            if (curLen > maxLen) {
                if (k > 0) {
                    k--;
                    curLen = 1;
                } else {
                    maxLen = curLen;
                    curLen = 1;
                }
            } else {
                maxLen = curLen;
                curLen = 1;
            }
        }
    }
    return Math.max(maxLen, curLen);
}
This code uses the readline module to read the input test cases. It then calls the `findMaxLen` function with the input string and maximum allowed changes. The `findMaxLen` function iterates over the string, keeping track of the maximum length of a sequence of identical characters and the current length of a sequence. If the current character is different from the previous one, it checks if the current length is greater than the maximum length. If it is, it checks if we can use more changes before making any changes. If we can't, it updates the maximum length. If the current length is greater than the maximum length, it resets the current length. At the end, it returns the maximum length.