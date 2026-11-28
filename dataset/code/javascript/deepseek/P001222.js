Here is the JavaScript code to solve the problem:

let readline = require('readline');

let rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

rl.question('Enter the value of N: ', function(N) {
    N = parseInt(N);
    if(N < 0 || N > 1000) {
        console.log('Invalid input, please enter a valid integer between 0 and 1000');
    } else {
        console.log('The ' + N + 'th Catalan number is: ' + catalan(N));
    }
    rl.close();
});

function catalan(n) {
    if(n === 0 || n === 1) return 1;

    var res = 0;
    for(var i = 0; i < n; i++) {
        res += catalan(i) * catalan(n - i - 1);
    }

    return res;
}

In this code, we use readline module to read the input from the user. For each input, we check if the input is a valid integer between 0 and 1000. If not, we print an error message. If the input is valid, we calculate and print the Nth Catalan number.

The catalan function calculates the Catalan number using dynamic programming. It iterates from 0 to n and for each i, it calculates the number of ways to choose nodes from the left subtree and from the right subtree of the tree.

The time complexity of this function is O(n^2), which is not efficient for large values of n, but it's fine for small values.