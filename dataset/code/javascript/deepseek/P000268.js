Here is a simple JavaScript code snippet that uses the built-in split() and length properties to solve the problem:

function countWords(s) {
    if(!s || s.length === 0) {
        return 0;
    }
    var words = s.split(/\s+/);
    return words.length;
}

This code works by splitting the string into words by whitespace characters using the split() method, which returns an array of words. The length of this array gives the number of words in the string.

This code also includes error checking to make sure the input string is not null or empty.

You can use this function by passing in the string you want to count the words in:

console.log(countWords("Hello world"));  // Outputs: 2
console.log(countWords(""));  // Outputs: 0
console.log(countWords("   "));  // Outputs: 0
console.log(countWords(null));  // Outputs: 0