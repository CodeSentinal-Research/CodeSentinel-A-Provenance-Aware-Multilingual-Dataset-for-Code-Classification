Here is the JavaScript code for the problem:

/**
 * @param {string} columnTitle
 * @return {number}
 */
function titleToNumber(columnTitle) {
    let result = 0, i = columnTitle.length - 1, factor = 1;
    while (i >= 0) {
        result += factor * (columnTitle.charCodeAt(i) - 64);
        factor *= 26;
        i--;
    }
    return result;
}

This code works by iterating over the input string from the end and multiplying the current character's position (which is determined by its Unicode value) by a factor of 26 (since there are 26 letters in the alphabet). This is done for each character in the string, essentially converting the column title to a number.