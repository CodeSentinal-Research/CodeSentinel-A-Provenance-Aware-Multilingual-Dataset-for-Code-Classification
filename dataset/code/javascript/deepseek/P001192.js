function maxAmount(input) {
    // Parse the input
    const [N, ...housings] = input;
    const houses = housings.map(Number);

    // Helper function to get max amount for robbing houses
    const rob = (houses, start, end) => {
        // Base case
        if (start > end) {
            return 0;
        }

        // Calculate max for robbing two houses
        const robTwo = houses[start] + rob(houses, start + 2, end);
        const notRobTwo = rob(houses, start + 1, end);

        // Return max between two cases
        return Math.max(robTwo, notRobTwo);
    };

    // Calculate max for robbing first and last houses
    const robFirstAndLast = houses[0] + rob(houses, 1, N - 1);

    return Math.max(robFirstAndLast, rob(houses, 2, N - 1));
}

To use the above code, you can call it with a JavaScript environment that supports the `process.stdin` and `process.stdout` modules. Here is an example:

const readline = require('readline');
const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let testCases = [
    [3, 1, 2, 3],
    [4, 1, 2, 3]
];

rl.question('Please enter the number of houses: ', (N) => {
    rl.question('Please enter the money in each house: ', (input) => {
        const housings = input.split(' ').map(Number);
        console.log(maxAmount(testCases[0]));
        rl.close();
    });
});

This example reads the number of houses and a list of money in each house from standard input, and outputs the maximum amount that can be robbed to standard output.