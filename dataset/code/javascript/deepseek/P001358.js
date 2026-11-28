Here is a JavaScript solution for the problem:

function generateAbbreviations(word) {
    const results = [];
    generateAbbreviation(word, 0, '', results);
    results.sort();
    return results;
}

function generateAbbreviation(word, index, abbreviation, results) {
    if (index >= word.length) {
        results.push(abbreviation);
        return;
    }

    // Keep the non-adjacent character groups unaltered
    generateAbbreviation(word, index + 1, abbreviation + word[index], results);

    // Replace the non-adjacent character groups with their counts
    for (let i = 1; i <= Math.min(word.length - index, 9); i++) {
        generateAbbreviation(word, index + i, abbreviation + i, results);
    }
}

console.log(generateAbbreviations('abbreviation'));

This code defines two functions `generateAbbreviations` and `generateAbbreviation`. The first function takes a word as input and calls the second function with the word, 0, an empty string, and a results array as arguments. It then sorts the results array and returns it.

The second function takes a word, index, abbreviation, and results array as arguments. It first checks if the index is greater than or equal to the length of the word, in which case it adds the abbreviation to the results array and returns.

Then it calls the first function recursively with the word, index + 1, the abbreviation + word[index], and the results array as arguments.

Next, it replaces the non-adjacent character groups in the word with their counts from 1 to the minimum of the length of the word and 9. It does this by calling the first function recursively with the word, index + i, the abbreviation + i, and the results array as arguments.