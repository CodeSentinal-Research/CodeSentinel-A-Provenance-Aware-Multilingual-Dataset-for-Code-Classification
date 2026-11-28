const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

rl.question('Enter number of cities: ', (N) => {
  let adjacencyMatrix = [];
  rl.setEncoding('utf8');

  rl.write('Enter adjacency matrix:\n');

  rl.on('line', (line) => {
    adjacencyMatrix.push(line.split(' ').map(Number));
    if (adjacencyMatrix.length < N) {
      rl.pause();
    }
  });

  rl.on('close', () => {
    const provinces = findProvinces(adjacencyMatrix, N);
    rl.write(`The number of provinces is: ${provinces}\n`);
    rl.close();
  });
});

function findProvinces(matrix, N) {
  let provinces = 0;
  let visited = new Array(N).fill(false);

  for (let i = 0; i < N; i++) {
    if (!visited[i]) {
      visitProvince(matrix, visited, i);
      provinces++;
    }
  }

  return provinces;
}

function visitProvince(matrix, visited, i) {
  visited[i] = true;

  for (let j = 0; j < visited.length; j++) {
    if (matrix[i][j] === 1 && !visited[j]) {
      visitProvince(matrix, visited, j);
    }
  }
}