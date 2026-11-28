Here is the JavaScript code for the problem:

let readline = require('readline');

let rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

let N = parseInt(rl.question());
let words = [];

rl.setPrompt('Enter two-letter word: ');

for(let i = 0; i < N; i++) {
  words.push(rl.question().toLowerCase());
}

function longestPalindrome(s) {
    if (s.length < 2) return s;
    if (s.length == 2) return s[0] === s[1] ? s : s[0];

    let result = s[0];
    for (let j = 1; j < s.length; j++) {
        let tmp = s[j];
        let temp = s;

        while (temp.length > 1 && temp !== tmp) {
            if (temp === tmp) {
                result = temp;
                break;
            }
            temp = temp.slice(1);
            tmp = tmp.slice(1);
        }
    }
    return result;
}

let longest = '';
for(let i = 0; i < N; i++) {
    let palindrome = longestPalindrome(words[i].split(''));
    if(palindrome.length > longest.length) {
        longest = palindrome;
    }
}

console.log(longest);
This code uses the readline module to read the input from the console, and then uses a loop to iterate through each word in the array. The longestPalindrome function is then used to find the longest palindrome that can be formed by concatenating a word from the list. The result is then printed to the console.

Please note that this code assumes that the input words are always valid two-letter words. If you want to add some error checking, you may need to handle cases where the input is not a valid two-letter word.