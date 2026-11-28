Here is a JavaScript solution for the problem using backtracking algorithm:

function solveCryptarithmeticPuzzle(word1, word2, word3) {
    const digits = '0123456789';
    const letters = [...word1].sort().join('');
    const map = {};

    function backtrack(idx = 0) {
        if (idx === word3.length) {
            return word1.split('').map(ch => map[ch] || ch).join('') === word3;
        }

        for (let i = 0; i < letters.length; i++) {
            map[letters[i]] = digits[idx];
            if (backtrack(idx + 1)) {
                return true;
            }
            map[letters[i]] = undefined;
        }

        return false;
    }

    if (backtrack()) {
        console.log(map);
    } else {
        console.log('IMPOSSIBLE');
    }
}

// usage
solveCryptarithmeticPuzzle('PUNK', 'NAPK', 'WUNK');

This code defines a function `solveCryptarithmeticPuzzle` that takes three words as input. It then generates a map of letter to digit. The `backtrack` function uses recursion to find all possible solutions. If a solution is found, it prints the solution. Otherwise, it prints IMPOSSIBLE.

Please note that this is a simple implementation and does not handle complex cases such as more than one solution or cases where the digits cannot be represented as letters.