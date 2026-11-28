Here is the JavaScript code that solves the problem:

var readline = require('readline');

var rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

var inputs = [];

rl.on('line', function(line) {
    inputs.push(line);
});

rl.on('close', function() {
    var N = parseInt(inputs[0]);
    var queries = inputs.slice(1, N+1).map(s => s.trim());
    var pattern = inputs[N+1].trim();

    for (var query of queries) {
        var isMatch = isCamelCaseMatching(query, pattern);
        console.log(isMatch ? 'YES' : 'NO');
    }

    rl.close();
});

function isCamelCaseMatching(query, pattern) {
    var camelCaseQuery = toCamelCase(query);
    var camelCasePattern = toCamelCase(pattern);
    return camelCaseQuery === camelCasePattern;
}

function toCamelCase(str) {
    return str.replace(/_[a-z]/g, function(match) {
        return match[1].toUpperCase();
    });
}

This code reads the inputs from stdin, splits them into queries and pattern, and then checks for each query whether it matches the pattern under camel-case matching rules. It uses the `toCamelCase` function to convert the pattern to camel case.