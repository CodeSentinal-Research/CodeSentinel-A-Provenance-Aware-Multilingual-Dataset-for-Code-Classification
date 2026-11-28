Here is the JavaScript code to solve the problem:

function isDigit(c) {
  if (c >= '0' && c <= '9') {
    console.log('Digit');
  } else {
    console.log('Not Digit');
  }
}

// Test the function with a character
isDigit('9'); // Outputs: Digit
isDigit('a'); // Outputs: Not Digit

In this code, we define a function `isDigit(c)` that checks if the character `c` is a digit. The character is checked against the ASCII values of the digits from 0 to 9. If the character falls within these ranges, it's a digit, so we print "Digit". Otherwise, it's not a digit, so we print "Not Digit".

To use the function, you can call it with a character as an argument. For example, `isDigit('9')` and `isDigit('a')`.