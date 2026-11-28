let fs = require('fs');
let input = fs.readFileSync('input.txt', 'utf8');
let lines = input.trim().split('\n');
let N = parseInt(lines[0]);
let dominoes = [];
for (let i = 1; i <= N; i++) {
    let domino = [parseInt(lines[i]), parseInt(lines[i+1])];
    domino.sort(function(a, b) {return a - b});
    dominoes.push(domino);
    i++;
}
let count = 0;
for (let i = 0; i < dominoes.length; i++) {
    if (dominoes[i][0] == dominoes[i][1] && i > 0 && dominoes[i][0] == dominoes[i-1][0]) {
        count++;
    }
}
console.log(count);
This JavaScript code reads the input from a file named 'input.txt', splits it into lines, processes each line, and computes the number of equivalent domino pairs. The input file is expected to contain an integer N at the first line, followed by N lines containing two integers each. The count of equivalent pairs is printed to the console.