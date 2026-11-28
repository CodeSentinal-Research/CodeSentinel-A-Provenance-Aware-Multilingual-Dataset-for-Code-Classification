Here is a simple JavaScript solution for the problem:

function longestDeletableWord(source, n, words) {
    // sort words by length in descending order
    words.sort((a, b) => b - a);

    // iterate through the words in the dictionary
    for(let i = 0; i < n; i++) {
        let word = words[i];
        // if the current word can be constructed from the source string, return it
        if (source.includes(word)) {
            return word;
        }
        // remove a character from the source string and check again
        for (let j = 0; j < source.length; j++) {
            let newSource = source.slice(0, j) + source.slice(j+1);
            if (newSource.includes(word)) {
                source = newSource;
                break;
            }
        }
    }

    // if no valid word is found, return an empty string
    return '';
}

This function first sorts the dictionary words by their lengths. Then it iterates through the dictionary. For each word, it tries to make the word from the source string. If it can be made, it returns the word. If not, it tries to remove a character from the source string and try again. This process is repeated until it finds a valid word or all the characters in the source string can't be deleted. If no valid word is found, it returns an empty string.