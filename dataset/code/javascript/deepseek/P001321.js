Here is the JavaScript code:

function letterCombinations(digits) {
    let phone = {
        '2': ['a', 'b', 'c'],
        '3': ['d', 'e', 'f'],
        '4': ['g', 'h', 'i'],
        '5': ['j', 'k', 'l'],
        '6': ['m', 'n', 'o'],
        '7': ['p', 'q', 'r', 's'],
        '8': ['t', 'u', 'v'],
        '9': ['w', 'x', 'y', 'z'],
    };

    const results = [];

    function backtrack(start, current) {
        if (current.length === digits.length) {
            results.push(current);
            return;
        }

        let digit = digits[start];
        for (let letter of phone[digit]) {
            current += letter;
            backtrack(start + 1, current);
            current = current.slice(0, -1);
        }
    }

    backtrack(0, '');

    results.sort();

    for (let i = 0; i < results.length; i++) {
        console.log(results[i]);
    }
}

// Test the function
letterCombinations('23');

In this code, we are creating a map of digits to their corresponding characters in the phone. Then we define a recursive function `backtrack` which takes the current digit (`start`) and the current combination (`current`). If the length of `current` is the same as `digits.length`, we know we've found a valid combination and add it to `results`. Otherwise, we pick a character for the current digit, add it to `current`, and recursively call `backtrack` with the next digit. We also need to remove the last character from `current` before backtracking. After all possible combinations have been found, we sort `results` and print each combination.