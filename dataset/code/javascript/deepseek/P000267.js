function replaceCharacter(S, oldChar, newChar) {
    return S.split(oldChar).join(newChar);
}

// Test the function
console.log(replaceCharacter('hello world', 'o', 'a')); // Output: 'hela warld'