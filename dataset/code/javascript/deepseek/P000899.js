Here is the JavaScript code to check if a given number is divisible by 3:

function checkDivisibilityBy3(N) {
    if (N % 3 === 0) {
        console.log(true);
    } else {
        console.log(false);
    }
}

You can use this function by passing an integer to it. For example:

checkDivisibilityBy3(18);  // Outputs: true
checkDivisibilityBy3(45);  // Outputs: false

This function checks if the remainder of the division of `N` by 3 is 0, which means `N` is divisible by 3.