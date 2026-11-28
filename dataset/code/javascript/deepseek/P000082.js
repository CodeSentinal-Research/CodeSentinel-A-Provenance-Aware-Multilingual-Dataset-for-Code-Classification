Here is the JavaScript code to check whether a given character is a special symbol or not:

function isSpecialSymbol(c) {
    // Check if the character is a space
    if (c === ' ') {
        console.log("Not Special Symbol");
    } else {
        console.log("Special Symbol");
    }
}

// Test the function
isSpecialSymbol('@'); // Output: Special Symbol
isSpecialSymbol(' '); // Output: Not Special Symbol
In this code, the `isSpecialSymbol` function checks if the input character `c` is a special symbol. It first checks if the character is a space (`' '`) and if it is, it logs "Not Special Symbol". Otherwise, it logs "Special Symbol". The function is then tested with two different characters, '@' and ' '.