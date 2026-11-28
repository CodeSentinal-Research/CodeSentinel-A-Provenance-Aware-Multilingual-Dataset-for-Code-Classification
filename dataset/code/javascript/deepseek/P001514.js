Here is a JavaScript solution for the problem using sliding window strategy. The idea is to keep track of the longest semirepetitive substring and update it as we iterate through the string.

function longestSemiRepetitiveSubstring(input) {
    let maxLength = 0;
    let currentLength = 0;
    let prevChar = null;

    for (let char of input) {
        if (char === prevChar) {
            currentLength++;
        } else {
            maxLength = Math.max(maxLength, currentLength);
            currentLength = 1;
        }
        prevChar = char;
    }

    maxLength = Math.max(maxLength, currentLength);

    return maxLength;
}

You can use the function by passing the string as an argument. For example, `longestSemiRepetitiveSubstring('11223211')` will return `3`.

This function works by iterating over the string. For each character, it checks if it is the same as the previous character. If it is, it increases the current length. If it is not, it updates the max length and resets the current length. It also keeps track of the previous character for the next iteration.