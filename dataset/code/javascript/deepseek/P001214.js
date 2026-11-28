Here is the JavaScript code for your problem:

process.stdin.resume();
process.stdin.on('data', (chunk) => {
    let input = chunk.toString().trim();
    console.log(minTurns(input));
    process.stdin.pause();
});

function minTurns(str) {
    let chars = Array.from(new Set(str));
    let maxChar = chars[chars.length - 1];
    let maxCount = str.split(maxChar).length - 1;
    return maxCount;
}
This code reads a string from standard input, creates a set to remove duplicates, and then finds the character with the highest count. The number of turns required is equal to the count of characters in the string plus one (for the extra turn needed to print the last character).