Here is the JavaScript code:

const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

let testCases = Number(rl.question().trim());

for (let i = 0; i < testCases; i++) {
    let [Text, Pattern] = rl.question().split(' ');

    console.log(countAnagramOccurrences(Text, Pattern));
}

function countAnagramOccurrences(Text, Pattern) {
    let count = 0;
    let patternLength = Pattern.length;
    let textLength = Text.length;

    for (let i = 0; i <= textLength - patternLength; i++) {
        if (isAnagram(Text.substring(i, i + patternLength), Pattern)) {
            count++;
        }
    }

    return count;
}

function isAnagram(substring, pattern) {
    let sortedPattern = pattern.split('').sort().join('');
    let sortedSubstring = substring.split('').sort().join('');

    return sortedPattern === sortedSubstring;
}
This script first reads the number of test cases from the input. Then it iterates over each test case, reading the two strings from the input and calling the `countAnagramOccurrences` function.

The `countAnagramOccurrences` function then checks each substring of the Text to see if it is an anagram of the Pattern. If it is, it increments the count.

The `isAnagram` function sorts the characters of the pattern and the substring, and checks if they are equal. If they are, the substring is an anagram of the pattern.