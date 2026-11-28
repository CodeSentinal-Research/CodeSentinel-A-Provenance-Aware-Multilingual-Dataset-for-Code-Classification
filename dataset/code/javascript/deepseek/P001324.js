const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

rl.question('Enter the value of K and N: ', (K, N) => {
    if (K < 1 || K > 9 || N < 1 || N > 60) {
        console.log('Invalid input, please enter values between 1 and 60 for K and N');
        return;
    }

    const result = [];
    function backtrack(start = 1, left = 9, sum = 0) {
        if (left < 0) return;
        if (sum + left > N) return;
        if (sum + left === N && Object.keys(left).length === K) {
            result.push(Object.values(left).map(String));
            return;
        }
        for (let i = start; i <= 9; i++) {
            left[i] = i;
            backtrack(i + 1, left, sum + i);
            delete left[i];
        }
    }

    backtrack();
    console.log(result);

    rl.close();
});
This JavaScript code will ask for the input values of K and N. It then checks if the inputs are within the valid range (1 to 9 for K, 1 to 60 for N). If the inputs are not valid, it will print an error message and stop.

If the inputs are valid, it will call a backtracking function that tries all possible combinations of K numbers from 1 to 9, and if the sum of the numbers in the current combination is equal to N, it will add the combination to the result array.

Finally, it will print the result array.

Please note that this code uses a recursive approach to find all combinations. The recursion is stopped when the combination is full (K numbers) and when the sum of numbers in the current combination is equal to N.