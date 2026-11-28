Sure, here's the JavaScript code. This code reads the input from the console and counts the number of edges.

let fs = require('fs');
let input = fs.readFileSync('stdin', 'utf-8');
let lines = input.split('\n');

let n = parseInt(lines[0]);
let count = 0;

for(let i = 1; i <= n; i++) {
    let line = lines[i];
    let adjacencyList = line.split(' ');
    count += adjacencyList.length - 1;
}

console.log(count);

This code reads the number of vertices (n) from the first line. It then iterates over each vertex and its adjacency list, counting the number of edges. The count is then printed to the console.

Please note that you need to provide the adjacency list of each vertex as input when running this code, as the input will be taken from the console. If you are running this code in a file, ensure that the adjacency list is provided as input when you run the script.