Here is the JavaScript solution for the problem:

let readline = require('readline');

let rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let N = 0;
let K = 0;

rl.on('line', function(line) {
    let parts = line.split(' ');
    N = parseInt(parts[0]);
    K = parseInt(parts[1]);
});

rl.on('line', function(line) {
    let nums = line.split(' ').map(Number);
    let result = 0;

    for (let i = 0; i < N; i++) {
        let product = nums[i];
        if (product >= K) continue;

        for (let j = i + 1; j < N; j++) {
            product *= nums[j];
            if (product >= K) result++;
        }
    }

    console.log(result);
});

In this code, we first read the input `N` and `K`. Then, we read `N` integers from the input and store them in an array. We then start a loop to calculate the product of all subarrays that end at `i`. If the product is greater than or equal to `K`, we increment the count. Finally, we print the count.

This code assumes that the input will be a list of `N` numbers followed by the `K` threshold. The numbers are separated by spaces in the input.

Please note that this code is not optimized for performance, it's just a simple solution. For a more optimized solution, you can use a prefix product and a binary search to find the subarrays with product less than `K`.