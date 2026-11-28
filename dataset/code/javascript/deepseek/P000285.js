Here is the JavaScript code for the problem:

function isSubsequence(s1, s2) {
    let i = 0;
    let j = 0;
    while (i < s1.length && j < s2.length) {
        if (s1[i] === s2[j]) {
            i++;
        }
        j++;
    }
    return i === s1.length;
}

You can call this function with two strings as arguments, like so:

console.log(isSubsequence('abc', 'axbyc'));  // Outputs: true
console.log(isSubsequence('abc', 'acb'));  // Outputs: false