Here is a JavaScript solution for the given problem:

function printLexicographical(n) {
    if (n == 0) {
        return;
    }

    for (let i = 1; i <= 9; i++) {
        printLexicographical(n * 10 + i);
    }
}

printLexicographical(1);

In this code, we use a recursive function `printLexicographical` which takes an integer `n` as input. If `n` is 0, we stop the recursion. For every other `n`, we call `printLexicographical` for `n` multiplied by 10 plus i, for 0 <= i <= 9.

This will print all numbers from 1 to N in lexicographical order. The `printLexicographical(1)` will initialize the recursion with 1.