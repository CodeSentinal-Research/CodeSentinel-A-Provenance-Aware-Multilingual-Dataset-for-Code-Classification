Here is the JavaScript code that solves the problem. 

function arrangeCoins(n) {
    if (n < 0 || n > Math.pow(2, 31) - 1) {
        throw new Error("Invalid input. Please enter a number between 0 and 2^31 - 1.");
    }

    let count = 0;
    let i = 1;

    while (n >= 0) {
        n -= i;
        count++;
        i++;
    }

    return count - 1; // subtract 1 because the last row is not counted
}

This function starts with a count of 0, then increments the count by 1 for each loop until the remaining coins are less than 0. This represents each row in the staircase. The last row is not counted in this process, because the loop ends when there are no more coins.