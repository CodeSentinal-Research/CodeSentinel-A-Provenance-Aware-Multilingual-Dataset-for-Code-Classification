Here is the JavaScript code for the problem:

function checkDuckNumber(n) {
    if (n < 1 || n > 10e9) {
        console.error("Invalid input. Please enter a positive integer between 1 and 10^9");
        return;
    }

    if (String(n).includes('0') && String(n).startsWith('0')) {
        console.log("Not Duck");
    } else {
        console.log("Duck");
    }
}

You can use this function by passing a number as a parameter, like so: `checkDuckNumber(1230);`

This function first checks if the input is valid. If the input is outside the range [1, 10^9], it prints an error message and returns from the function.

Then it checks if the input number includes a '0' and starts with a '0'. If both conditions are met, it prints 'Not Duck'. Otherwise, it prints 'Duck'.