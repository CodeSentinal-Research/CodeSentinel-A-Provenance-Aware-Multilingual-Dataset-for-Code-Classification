Here is the JavaScript code that checks whether a given number is a Harshad number or not:

function isHarshadNumber(n) {
    if (n < 1 || n > 1000000) {
        console.log("Invalid input. Please enter a positive integer between 1 and 10^6");
        return false;
    }

    let sum = 0;
    let temp = n;

    while (temp > 0) {
        sum += temp % 10;
        temp = Math.floor(temp / 10);
    }

    if (n % sum === 0) {
        console.log("Harshad");
    } else {
        console.log("Not Harshad");
    }
}

isHarshadNumber(15);
This code first checks if the input is within the constraints, then calculates the sum of the digits and finally checks if the input is divisible by the sum of its digits. The `Math.floor(temp / 10)` is used to remove the last digit from the number and the `%` operator is used to find the remainder of the division.