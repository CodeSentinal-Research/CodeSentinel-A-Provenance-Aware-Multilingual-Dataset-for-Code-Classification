Here is the JavaScript code that will solve the problem:

function removeDuplicateCharacters(S) {
    let str = '';
    let lastChar = '';
    for (let i = 0; i < S.length; i++) {
        if (S[i] !== lastChar) {
            str += S[i];
            lastChar = S[i];
        }
    }
    return str;
}

This function will create a new string and add characters to it only if they haven't been added yet. The 'lastChar' variable will keep track of the last character added to the new string. This way, all duplicate characters are removed, but the order of the characters in the original string is preserved.