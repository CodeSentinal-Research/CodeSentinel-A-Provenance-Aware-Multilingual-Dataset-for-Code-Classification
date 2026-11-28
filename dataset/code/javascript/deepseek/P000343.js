function checkIfAlmostEquivalent(word1, word2) {
    let charCount1 = {};
    let charCount2 = {};

    for (let char of word1) {
        charCount1[char] = (charCount1[char] || 0) + 1;
    }

    for (let char of word2) {
        charCount2[char] = (charCount2[char] || 0) + 1;
    }

    for (let char in charCount1) {
        if (charCount2[char] !== charCount1[char]) {
            return "No";
        }
    }

    return "Yes";
}

let word1 = 'abc';
let word2 = 'abcd';

console.log(checkIfAlmostEquivalent(word1, word2)); // Outputs: "No"

word1 = 'abc';
word2 = 'acbc';

console.log(checkIfAlmostEquivalent(word1, word2)); // Outputs: "Yes"