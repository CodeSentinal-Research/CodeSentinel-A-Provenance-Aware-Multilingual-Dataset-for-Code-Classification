Here is the JavaScript code that solves the problem:

let readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

rl.question('Enter number of vertices and edges: ', (N) => {
    let graph1 = Array(N).fill(0).map(() => Array(N).fill(0));
    let graph2 = Array(N).fill(0).map(() => Array(N).fill(0));

    rl.close();

    rl.question('Enter edges for graph 1 (source and destination): ', (source, dest, forwards) => {
        graph1[source - 1][dest - 1] = 1;
        rl.pause();
        rl.question('Enter edges for graph 1 (continue with source and destination) or press enter to continue: ', (source, dest) => {
            graph1[source - 1][dest - 1] = 1;
            checkIsomorphic(graph1, graph2, N);
        });
    });
});

function checkIsomorphic(graph1, graph2, N) {
    if (graph1.length !== graph2.length) {
        console.log('NO');
        return;
    }

    let isIsomorphic = true;

    for (let i = 0; i < N; i++) {
        if (graph1[i].join('') !== graph2[i].join('')) {
            isIsomorphic = false;
            break;
        }
    }

    if (isIsomorphic) {
        console.log('YES');
    } else {
        console.log('NO');
    }
}

This code reads the number of vertices and edges, and then reads the edges for each graph. It then checks if the graphs are isomorphic by comparing the adjacency matrices. If the adjacency matrices are equal, the graphs are isomorphic.