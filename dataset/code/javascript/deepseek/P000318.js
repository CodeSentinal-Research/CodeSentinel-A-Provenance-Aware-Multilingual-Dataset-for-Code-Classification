Here's a simple JavaScript solution for the problem:

function validWordAbbreviation(word, abbr) {
    let i = 0, j = 0;

    while(i < word.length && j < abbr.length) {
        if(word[i] == abbr[j] || abbr[j] == '.') {
            i++;
            j++;
        } else if(isNaN(abbr[j])) {
            return "No";
        } else {
            let repeat = '';
            while(j < abbr.length && isNaN(abbr[j])) {
                repeat += abbr[j];
                j++;
            }
            i += repeat;
        }
    }

    return i == word.length && j == abbr.length;
}

This function iterates through the characters of the word and abbreviation, checking if they are equal, or if the abbreviation is a period. If they are equal, it increments the index in both strings. If they are not equal, and the character at the index in the abbreviation is not a number, it returns "No". If the character at the index in the abbreviation is a number, it repeats the character the number of times specified by the number.

After the while loop ends, if the indices i and j are the same as the lengths of the word and abbreviation, it means that the word and abbreviation match, and it returns true. Otherwise, it returns false.

This function assumes that the input strings are ASCII characters. If the input can contain non-ASCII characters, you would need to adjust the function to handle the characters correctly.