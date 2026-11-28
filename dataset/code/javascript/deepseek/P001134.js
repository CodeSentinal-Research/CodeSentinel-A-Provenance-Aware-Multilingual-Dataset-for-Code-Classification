Here is the JavaScript code for the House Robber problem.

const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

rl.question('Enter the number of houses: ', (numHouses) => {
    rl.question('Enter the amount of money in each house: ', (houseValues) => {
        const houses = houseValues.split(' ').map(Number);
        console.log(robHouses(houses));
        rl.close();
    });
});

function robHouses(houses) {
    if (houses.length === 0) {
        return 0;
    }
    if (houses.length === 1) {
        return houses[0];
    }
    if (houses.length === 2) {
        return Math.max(houses[0], houses[1]);
    }

    let prev1 = 0, prev2 = 0, prev3 = 0;
    for (let i = 0; i < houses.length; i++) {
        if (i === 0) {
            prev3 = prev2;
            prev2 = prev1;
            prev1 = houses[i];
        } else if (i === 1) {
            prev3 = prev2;
            prev2 = Math.max(prev1, houses[i]);
            prev1 = houses[i];
        } else if (i === 2) {
            prev3 = Math.max(prev2, houses[i]);
            prev2 = houses[i];
            prev1 = Math.max(prev1, houses[i]);
        } else {
            prev3 = Math.max(prev2, prev1 + houses[i]);
            prev1 = prev2;
            prev2 = prev3;
        }
    }

    return prev3;
}

This code uses dynamic programming to find the maximum amount of money that can be robbed. It maintains three variables prev1, prev2, and prev3 to store the maximum amount of money that can be robbed up to the (i-1)th house, the maximum amount of money that can be robbed up to the (i-2)th house, and the maximum amount of money that can be robbed up to the (i-3)th house. It uses the values of the houses array in the loop to update these variables. The final maximum amount of money that can be robbed is returned as the result.

This code handles the input for the number of houses and the amount of money in each house. After receiving the input, it calls the `robHouses` function with the houses array as argument, and prints the returned result.