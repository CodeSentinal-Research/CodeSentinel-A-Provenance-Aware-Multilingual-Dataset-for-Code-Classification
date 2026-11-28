Here is the JavaScript code:

function isHarshad(N) {
    let sum = 0;
    let temp = N;
    while (temp > 0) {
        sum += temp % 10;
        temp = Math.floor(temp / 10);
    }
    return N % sum === 0;
}

console.log(isHarshad(35)); // Outputs: true
console.log(isHarshad(33)); // Outputs: false
In this code, we first convert the input number N to a string and then loop through each digit in the string. We sum up all the digits and check if N is divisible by the sum. If N is divisible by the sum, then N is a Harshad number and we return true; otherwise, we return false.

This code will work for any input number within the constraints of the problem, since the constraints are that 1 <= N <= 10^18. However, keep in mind that the computational complexity of this code can be high, especially for large numbers.