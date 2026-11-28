Here is the JavaScript code:

var readline = require('readline');

var inputReader = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

function solve(input) {
    inputReader.close();
    var strings = input.split('\n').slice(1);
    var prefix = strings[0];

    for (var i = 1; i < strings.length; i++) {
        while (strings[i].indexOf(prefix) != 0) {
            prefix = prefix.substring(0, prefix.length - 1);

            if (prefix.length == 0) {
                console.log('');
                return;
            }
        }
    }

    console.log(prefix);
}

process.stdin.on('line', function (line) {
    solve(line);
});

This code reads a list of strings from standard input. It then finds the longest common prefix among the strings. The `solve` function takes a string, `prefix`, and iteratively reduces it until it is no longer a prefix of the next string in the array, `strings`. The longest common prefix is then printed to standard output.