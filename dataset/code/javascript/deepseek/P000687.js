Here is the JavaScript code to solve the given problem:

function digitSum(N) {
    if (N === 0) {
        return 0;
    } else {
        return (N % 10) + digitSum(Math.floor(N / 10));
    }
}

This function works by checking if the input number `N` is 0. If it is, it returns 0 as the sum of digits. If `N` is not 0, it takes the last digit of `N` (using the modulus operator `%`) and adds it to the sum of the remaining digits (using the `Math.floor` function to remove the last digit and `Math.floor` division). This process repeats until all digits have been processed.