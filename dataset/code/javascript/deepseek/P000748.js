Here is the JavaScript code for the given problem. This code uses recursion to generate all the possible dice roll sequences. The function `generateSequences` accepts two parameters: `target` and `sequence`. The `target` parameter represents the sum of the dice rolls and `sequence` is an array that stores the current dice roll sequence.

function generateSequences(target, sequence = []) {
    if (sequence.length > 6) return;
    if (sequence.reduce((a, b) => a + b, 0) === target) {
        console.log(sequence.join('+'));
    }

    for (let i = 1; i <= 6; i++) {
        if (sequence.length > 0 && sequence[sequence.length - 1] < i) break;
        generateSequences(target, [...sequence, i]);
    }
}

generateSequences(5);

This code will print all sequences of dice rolls (values from 1 to 6) whose sum equals to `5`.

Please note that this code has a time complexity of `O(10^6)`. This is because there are up to 10^6 possible sequences when the sum of dice rolls is `5`.

Please also note that the provided code does not handle inputs that are not integers or are out of range (i.e., 1 <= target <= 20). In a production environment, you should add checks for such cases and handle them appropriately.