Here is a JavaScript solution for the given problem. This solution uses recursive approach to find all the possible letter combinations for a phone number given as a string of digits.

function letterCombinations(digits) {
    if (digits.length === 0) return [];

    const map = {
        '2': 'abc',
        '3': 'def',
        '4': 'ghi',
        '5': 'jkl',
        '6': 'mno',
        '7': 'pqrs',
        '8': 'tuv',
        '9': 'wxyz'
    };

    let result = [];

    function backtrack(start = 0, current = '') {
        if (current.length === digits.length) {
            result.push(current);
            return;
        }

        let letters = map[digits[start]];
        for (let i = 0; i < letters.length; i++) {
            backtrack(start + 1, current + letters[i]);
        }
    }

    backtrack();

    return result;
}

This function creates a map of digit characters to their corresponding letters. Then it uses a recursive function `backtrack` to generate all possible combinations of the input characters.

The `backtrack` function takes two parameters, `start` and `current`, which represent the current character index and the current combination of characters, respectively. If the current character index is equal to the length of the input digits, it adds the current combination to the result and returns.

If the current character index is less than the length of the input digits, it finds the corresponding letters for the current character and iterates over each letter. Then it recursively calls `backtrack` with the updated parameters.

The `letterCombinations` function sets the initial parameters for `backtrack`, calls `backtrack`, and returns the result.