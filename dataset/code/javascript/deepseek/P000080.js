// Function to check if a character is a alphabet
function isAlphabet(c) {
    // Check if the character is a printable character (ASCII 32 to 126)
    if (c.charCodeAt(0) >= 32 && c.charCodeAt(0) <= 126) {
        // Check if the character is a letter (a to z or A to Z)
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            console.log('Alphabet');
        } else {
            console.log('Not Alphabet');
        }
    } else {
        console.log('Not Alphabet');
    }
}

// Test the function
isAlphabet('a'); // Alphabet
isAlphabet('A'); // Alphabet
isAlphabet('1'); // Not Alphabet
isAlphabet(' '); // Not Alphabet