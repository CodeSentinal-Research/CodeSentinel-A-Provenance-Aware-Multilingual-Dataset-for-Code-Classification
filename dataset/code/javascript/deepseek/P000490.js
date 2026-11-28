Here's a simple JavaScript code that implements the problem:

function backspaceCompare(s, t) {
    let i = s.length - 1, j = t.length - 1;
    let sBk = '', tBk = '';

    while(i >= 0 || j >= 0) {
        while(i >= 0 && s[i] != '#') {
            sBk += s[i];
            i--;
        }
        while(j >= 0 && t[j] != '#') {
            tBk += t[j];
            j--;
        }
        i--; j--;
    }

    return sBk === tBk;
}

In this code, we are iterating from the end of both the strings and for each character, if it is not a '#', we are appending it to a temporary string. If it is a '#', we are ignoring it. After the processing, we are checking if the processed strings are equal. If they are equal, we return true, else false.

You can use the function as follows:

console.log(backspaceCompare('abc#d', 'abcdef#')); // output: true
console.log(backspaceCompare('ab#c', 'ad#c')); // output: true
console.log(backspaceCompare('a##c', '#a#c')); // output: true
console.log(backspaceCompare('', '')); // output: true
console.log(backspaceCompare('a#', 'b')); // output: false