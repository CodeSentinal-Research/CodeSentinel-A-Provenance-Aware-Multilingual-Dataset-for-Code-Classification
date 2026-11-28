let readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

let arr = [];

rl.on('line', function(line) {
    arr.push(line.split(' '));
    if(arr.length == arr[0][0]+1) rl.close();
}).on('close', function() {
    const [N, M] = arr[0];
    const graph = Array.from(Array(N), (_, i) => i);
    arr.slice(1).forEach(edge => {
        const [u, v] = edge;
        graph[v] = graph[v].filter(x => x !== u);
    });

    const result = graph.reduce((acc, v, i) => {
        return acc + graph[i].length;
    }, 0);

    console.log(result);
    process.exit();
});