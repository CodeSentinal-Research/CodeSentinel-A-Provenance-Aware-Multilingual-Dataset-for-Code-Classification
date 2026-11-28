function boldSubstrings(S, dictionary) {
    // Initialize an empty result string
    let result = '';

    // Iterate over each character in the string
    for (let i = 0; i < S.length; i++) {
        // If the character is in the dictionary, wrap it with bold tags
        if (dictionary.includes(S[i])) {
            result += '<b>' + S[i] + '</b>';
        } else {
            result += S[i];
        }
    }

    // Return the result string
    return result;
}
This function takes a string `S` and a list of words as input. It iterates over each character in `S`. If the character is in the dictionary (given as input), it wraps the character with bold tags (`<b>` and `</b>`) and adds it to the result string. If the character is not in the dictionary, it simply adds the character to the result string.