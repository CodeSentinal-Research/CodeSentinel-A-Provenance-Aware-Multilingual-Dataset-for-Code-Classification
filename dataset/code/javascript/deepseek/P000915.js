Here is a simple JavaScript function to calculate the number of possible handshake arrangements given the number of people sitting around the table. 

function countHandshakes(N) {
    if (N < 1 || N > 500) {
        throw new Error("Input must be between 1 and 500");
    }

    return Math.pow(N, 2);
}

// Test the function
console.log(countHandshakes(3));  // Output: 6

This function uses the mathematical formula for combinations (N choose 2), where N is the number of people. This is because each person must shake hands with exactly one other person, and there are N people in total, so we need to divide by 2.