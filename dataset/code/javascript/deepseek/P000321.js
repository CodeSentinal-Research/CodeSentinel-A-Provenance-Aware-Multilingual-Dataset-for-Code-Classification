Here is the JavaScript code to solve the problem:

function findWords(words) {
    // Create an array with all the letters from the first row
    let firstRow = 'qwertyuiopQWERTYUIOP';
    firstRow = firstRow.split('');

    // Check each word in the list
    return words.filter(word => {
        // Create an array with the characters in the current word
        let wordChars = word.split('');

        // Check if all the characters in the word are in the first row
        return wordChars.every(char => firstRow.includes(char));
    });
}
This function takes an array of words as input and returns an array of words that can be typed using only the letters of one row of an American keyboard. It uses the `every` method to check if all characters in the word are in the first row, and the `includes` method to check if a character is in the first row.