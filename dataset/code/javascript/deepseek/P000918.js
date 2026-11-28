Here is the JavaScript code:

function countCircularArrangements(n) {
    if(n === 1) {
        return 1;
    } else {
        let result = 1;
        for(let i = 2; i <= n; i++) {
            result *= i;
        }
        return result;
    }
}

console.log(countCircularArrangements(5)); // Outputs: 120

This function calculates the factorial of the number `n` and returns it as the number of circular arrangements. The factorial of a number is the product of all positive integers less than or equal to that number. In this case, we calculate the factorial of `n`, which is the product of all positive integers less than or equal to `n`.

Please note that this function does not check if `n` is a valid input, such as if `n` is not an integer or if `n` is not within the constraints (1 ≤ N ≤ 20). You may want to add input validation depending on your specific use case.