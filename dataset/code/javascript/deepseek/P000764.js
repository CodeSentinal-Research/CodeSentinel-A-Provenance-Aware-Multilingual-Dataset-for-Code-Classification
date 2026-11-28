Here's the JavaScript code for the given problem.

function decodeAtIndex(s, K) {
    for (let i = s.length - 1; i >= 0; i--) {
        if (isNaN(s[i])) {
            K--;
            if (K === 0) {
                return s[i];
            }
        } else {
            let repeat = parseInt(s[i]);
            K = Math.floor(K / repeat);
            if (K === 0) {
                return s[i];
            }
        }
    }
}

This function works by iterating over the string from right to left, checking each character. If the character is not a digit, it counts it as a string of length one. Otherwise, it multiplies the count by the number of characters in the decoded string to get the next string to consider. 

The function then recursively decodes the next string until it reaches the K-th character, then returns this character.

Please note, the provided code assumes that the input string only contains lowercase English letters and digits, and the input integer K is a positive integer. 

This implementation uses the mathematical property of repeated strings. It is possible to create a string of a certain number of repeated strings by concatenating one character repeated 'n' times. So if the character is a digit, it means we have to repeat the character by the number of characters in the decoded string. Otherwise, it's a normal character.