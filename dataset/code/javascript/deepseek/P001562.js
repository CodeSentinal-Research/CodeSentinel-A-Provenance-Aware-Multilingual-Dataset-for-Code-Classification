Here is the JavaScript code:

function longestSubstringWithKDistinctCharacters(s, k) {
    let left = 0, right = 0;
    let map = new Map();
    let distinctCharacters = 0;
    let maxLength = 0;

    while (right < s.length) {
        if (!map.has(s[right])) {
            distinctCharacters++;
            map.set(s[right], 1);
        } else {
            map.set(s[right], map.get(s[right]) + 1);
        }

        if (distinctCharacters === k) {
            maxLength = Math.max(maxLength, right - left + 1);
            if (maxLength === s.length) {
                return -1;
            }

            if (map.get(s[left]) === 1) {
                map.delete(s[left]);
                distinctCharacters--;
            } else {
                map.set(s[left], map.get(s[left]) - 1);
            }

            left++;
        }

        right++;
    }

    return maxLength;
}

const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let s = '';
rl.question('Enter the string: ', (str) => {
    s = str;
    rl.question('Enter the number of distinct characters: ', (num) => {
        console.log(longestSubstringWithKDistinctCharacters(s, num));
        rl.close();
    });
});

This JavaScript code reads the input from the console and logs the length of the longest substring with exactly K distinct characters. If there's no such substring, it returns -1.