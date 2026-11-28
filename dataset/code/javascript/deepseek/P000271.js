Here is the JavaScript code for the problem:

function checkIfRotation(s1, s2) {
    if (s1.length !== s2.length) {
        return 'No';
    }
    var doubleStr = s1 + s1;
    if (doubleStr.includes(s2)) {
        return 'Yes';
    } else {
        return 'No';
    }
}

This code first checks if the length of the two strings are equal. If not, it returns 'No' because a rotation of a string by a different length is not possible. Then it constructs a string that is the concatenation of the first string and itself. If the second string is a substring of this double string, it means that the second string is a rotation of the first string, so it returns 'Yes'. Otherwise, it returns 'No'.

You can test this code with this line in your browser's console:
console.log(checkIfRotation('abc', 'cab'));  // 'Yes'
console.log(checkIfRotation('abc', 'bca'));  // 'No'
console.log(checkIfRotation('abc', 'bcd'));  // 'No'