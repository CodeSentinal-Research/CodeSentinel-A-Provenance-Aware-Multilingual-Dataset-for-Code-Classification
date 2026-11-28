Here is the JavaScript code to generate all permutations of a string:

function generatePermutations(str, prefix = '') {
    if (str.length <= 1) {
        console.log(prefix + str);
    } else {
        for (let i = 0; i < str.length; i++) {
            let remaining = str.substring(0, i) + str.substring(i + 1);
            generatePermutations(remaining, prefix + str[i]);
        }
    }
}

generatePermutations('abc');

This code defines a function `generatePermutations` that takes a string `str` and a string `prefix`. If `str` is an empty string, it prints `prefix`. Otherwise, for each character in `str`, it recursively calls `generatePermutations` with the remaining part of `str` and the character added to `prefix`. This process continues until `str` is empty.

The input to this code is a string, and the output will be all possible permutations of the string, one per line.