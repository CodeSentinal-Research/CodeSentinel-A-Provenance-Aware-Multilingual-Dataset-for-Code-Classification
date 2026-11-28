Here is the JavaScript code for the problem:

function lcm(a, b) {
    if (b % a === 0) return a;
    else return a * b / gcd(a, b);
}

function gcd(a, b) {
    if (!b) return a;
    else return gcd(b, a % b);
}

function lcmOfArray(nums) {
    let result = 1;
    for (let num of nums) {
        result = (result * num) / gcd(result, num);
    }
    return result;
}

console.log(lcmOfArray([2, 7, 3]));

In this code, we have three functions:

1. `lcm(a, b)`: This function calculates the least common multiple (LCM) of two numbers. It uses the Euclidean algorithm to find the greatest common divisor (gcd) of the two numbers.

2. `gcd(a, b)`: This function calculates the greatest common divisor of two numbers. It recursively calls itself until the gcd of a and b is found.

3. `lcmOfArray(nums)`: This function calculates the LCM of an array of numbers. It calculates the LCM of the first two numbers, then calculates the LCM of the result and the next number, and so on. It uses the formula `result = (result * num) / gcd(result, num)` to keep updating the result as the LCM of the numbers.

The `console.log(lcmOfArray([2, 7, 3]))` line is an example of how to use the `lcmOfArray` function. It calculates the LCM of the numbers 2, 7, and 3 in the array [2, 7, 3] and prints the result to the console.