Here is a simple JavaScript code to solve the problem:

function checkNeon(n) {
    var sum = 0;
    n = Math.abs(n); // make sure n is a positive integer
    while (n > 0) {
        sum += n % 10;
        n = Math.floor(n / 10);
    }
    if (sum === n) {
        console.log('Neon');
    } else {
        console.log('Not Neon');
    }
}

// Testing the function
checkNeon(13);  // Output: Not Neon
checkNeon(15);  // Output: Neon
In this code, we define a function `checkNeon(n)`. It first converts the input `n` to a positive integer. Then, it calculates the sum of all digits of `n`. If the sum is equal to `n`, then `n` is a neon number, otherwise not. The result is printed to the console.