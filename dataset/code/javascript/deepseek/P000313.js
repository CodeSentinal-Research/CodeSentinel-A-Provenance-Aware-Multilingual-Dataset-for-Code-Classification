Here is a simple JavaScript solution that uses the isNaN() function in combination with a regular expression to validate a number.

function isValidNumber(str) {
    var regExp = /^-?\d+(\.\d+)?$/;
    if (regExp.test(str)) {
        console.log('Valid');
    } else {
        console.log('Invalid');
    }
}

// Test the function
isValidNumber('123'); // Output: Valid
isValidNumber('123.45'); // Output: Valid
isValidNumber('-123'); // Output: Valid
isValidNumber('abc'); // Output: Invalid

This function `isValidNumber(str)` takes a string `str` as input. A regular expression `regExp` is defined to match the pattern of a valid number. `isNaN(str)` is used to check if the string can be converted to a number, and `test(str)` is used to run the regular expression test on the string.

If the regular expression test returns true (i.e., the string is a valid number), the function prints 'Valid'. Otherwise, it prints 'Invalid'.