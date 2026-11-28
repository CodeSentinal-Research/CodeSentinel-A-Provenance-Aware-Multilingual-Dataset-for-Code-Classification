Here is the JavaScript code to solve this problem:

function digitReplace(s) {
    let result = '';
    for (let i = 0; i < s.length; i++) {
        if (!isNaN(s[i])) {
            if (i > 0 && !isNaN(s[i - 1])) {
                result += String.fromCharCode(96 + (s[i - 1] - '0' + 1) % 26 + ''.padStart(i, '0'));
            } else {
                result += String.fromCharCode(96 + (s[i] - '0') % 26 + ''.padStart(i, '0'));
            }
        } else {
            result += s[i];
        }
    }
    return result;
}

This function iterates over each character in the string. If the character is a digit, it replaces it with the character that is shift positions after the previous character. It uses ASCII values to achieve this. `96` is added to the ASCII value of 'a' to get the ASCII value of '0', and then it adds 1 to the ASCII value of the current character and modulo 26 to wrap around to 'a' if needed. The `padStart` method is used to pad the index with zeros if necessary.