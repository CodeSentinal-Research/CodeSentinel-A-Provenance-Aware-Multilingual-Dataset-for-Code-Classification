Here is the JavaScript code for the problem:

function reverseInteger(x) {
    let reversed = 0;
    while (x != 0) {
        reversed = reversed * 10 + x % 10;
        x = Math.floor(x / 10);
        if ((reversed > Math.pow(2, 31) - 1) || (reversed < -Math.pow(2, 31))) {
            return 0;
        }
    }
    return reversed;
}

console.log(reverseInteger(123)); // 321
console.log(reverseInteger(-123)); // -321
console.log(reverseInteger(123456)); // 0

In this code, we use a while loop to continuously remove the last digit from `x` and add it to `reversed`, and then shift the digits in `reversed` by one digit to the left. If the reversed number overflows, we return 0. The last line of the code demonstrates the usage of the function with examples.