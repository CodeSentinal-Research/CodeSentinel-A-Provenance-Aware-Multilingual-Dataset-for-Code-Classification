Here is the JavaScript code that computes the GCD of an array:

function gcd(a, b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

function findGCD(nums) {
    let num1 = nums[0];
    let num2 = nums[1];
    let gcdNum = gcd(num1, num2);

    for (let i = 2; i < nums.length; i++) {
        gcdNum = gcd(gcdNum, nums[i]);
    }

    return gcdNum;
}

// Testing
console.log(findGCD([2, 4, 6, 8, 16])); // Output: 4

In this code, we first define a helper function `gcd(a, b)` that computes the greatest common divisor of two numbers using the Euclidean algorithm.

Then, we define a main function `findGCD(nums)` that computes the GCD of an array of numbers using the helper function. The GCD of two numbers is the GCD of the first two numbers, then the GCD of the result and the next number, and so on, until we reach the end of the array.

Finally, we test the function with an array of numbers `[2, 4, 6, 8, 16]` and print the result.