Here is the JavaScript code for the problem:

const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let testCases = parseInt(rl.readline());

for(let i = 0; i < testCases; i++){
    let [n, m] = rl.readline().split(' ').map(Number);
    let alice = new Array(n+1).fill(0);
    let bob = new Array(n+1).fill(0);
    let graph = new Array(m).fill(null).map(() => []);
    let count = new Array(n+1).fill(0);

    for(let j = 0; j < m; j++){
        let [type, u, v] = rl.readline().split(' ').map(Number);
        if(type === 1) alice[u]++;
        else if(type === 2) bob[v]++;
        else graph[u].push(v);
        count[u]++;
    }

    let max = 0;
    for(let u = 1; u <= n; u++){
        if(alice[u] > 0 && bob[u] > 0){
            if(alice[u] + bob[u] - 1 > max) max = alice[u] + bob[u] - 1;
        }else if(alice[u] > 0){
            if(alice[u] > max) max = alice[u];
        }else if(bob[u] > 0){
            if(bob[u] > max) max = bob[u];
        }
    }

    console.log(max === 0 ? -1 : max);
}

rl.close();
This code reads the number of test cases from the standard input and then for each test case, it reads the number of vertices and edges and their type. It then calculates the number of edges that can be removed while ensuring both Alice and Bob can still traverse the entire graph. If it is not possible to remove any edge, it prints -1.