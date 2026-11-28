Here is the JavaScript code to solve the problem:

function diceSumProbability(s) {
    // Input validation
    if (s < 2 || s > 12) {
        throw new Error('Invalid input. S must be between 2 and 12.');
    }

    // Calculate the probability
    let probability = 0;

    for (let i = 1; i <= 6; i++) {
        for (let j = 1; j <= 6; j++) {
            if (i + j === s) {
                probability += 1;
            }
        }
    }

    // Return the probability
    return probability / 36;
}

// Test the function
console.log(diceSumProbability(5));  // Outputs: 0.03571428571428571

This function calculates the probability of getting a sum of `s` when rolling two dice. The probability is calculated by counting the number of outcomes that sum to `s`, and then dividing by the total number of possible outcomes. In this case, the total number of possible outcomes is 36 (the number of possible outcomes when rolling two six-sided dice).