function lastNonRepeatingCharacter(S) {
    // Initialize an empty object to store the characters and their counts
    let count = {};
    
    // Loop through the string and count the characters
    for (let i = 0; i < S.length; i++) {
        count[S[i]] = (count[S[i]] || 0) + 1;
    }
    
    // Loop through the string in reverse order
    for (let i = S.length - 1; i >= 0; i--) {
        // If the character count is 1 and it's not a repeating character, return it
        if (count[S[i]] === 1 && S[i] !== S[i + 1]) {
            return S[i];
        }
    }
    
    // If no non-repeating character is found, return -1
    return -1;
}
This function first counts the occurrences of each character in the string, then traverses the string from end to beginning to find the last character that appears only once. If no such character is found, it returns -1.