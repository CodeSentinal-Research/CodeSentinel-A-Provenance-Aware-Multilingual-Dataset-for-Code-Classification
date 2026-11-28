Here is the JavaScript code to solve the problem:

function isNeonNumber(n) {
    if (n < 10 || n > 1000000000) {
        return "Invalid input. Enter a number between 0 and 10^9.";
    }

    let squareDigitSum = 0;
    let temp = n;

    while (temp > 0) {
        let digit = temp % 10;
        squareDigitSum += digit;
        temp = Math.floor(temp / 10);
    }

    return squareDigitSum === n;
}

This function will check if the input number is a Neon number or not. The function first checks if the number is in the range of 0 to 10^9. Then it calculates the sum of the square of each digit in the number. If the sum is equal to the original number, it returns true, else false.