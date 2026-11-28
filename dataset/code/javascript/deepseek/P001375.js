Here is the JavaScript code:

const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let s = '';
rl.question('Enter first string: ', (str) => {
    s = str;
    rl.question('Enter second string: ', (str) => {
        const t = str;
        if (isAnagram(s, t)) {
            console.log('YES');
        } else {
            console.log('NO');
        }
        rl.close();
    });
});

function isAnagram(s, t) {
    if (s.length !== t.length) {
        return false;
    }
    const count = new Array(256).fill(0);
    for (let i = 0; i < s.length; i++) {
        count[s.charCodeAt(i)]++;
        count[t.charCodeAt(i)]--;
    }
    for (let i = 0; i < 256; i++) {
        if (count[i] !== 0) {
            return false;
        }
    }
    return true;
}

In this code, we use a count array to store the count of each character in the strings. We iterate through both strings and for each character, we increment the count in the count array for the first string, and decrement the count in the count array for the second string. If at the end of the iteration, the count array still contains non-zero values, it means the strings are not anagrams, so we return false. Otherwise, we return true.