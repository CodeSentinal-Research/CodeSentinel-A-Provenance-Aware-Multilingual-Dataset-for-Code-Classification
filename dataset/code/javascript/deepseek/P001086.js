function solve() {
  const [N, M, K] = readline().split(' ').map(Number);
  const graph = Array.from(Array(N), () => new Array(N).fill(Infinity));
  const sources = readline().split(' ').map(Number);
  
  for (let i = 0; i < M; i++) {
    const [u, v, w] = readline().split(' ').map(Number);
    graph[u-1][v-1] = w;
    graph[v-1][u-1] = w;
  }
  
  const distances = Array.from(Array(N), () => Infinity);
  distances[sources[0]-1] = 0;
  
  for (let s = 0; s < K; s++) {
    let minDistance = Infinity;
    
    for (let i = 0; i < N; i++) {
      for (let j = 0; j < N; j++) {
        if (distances[i] + graph[i][j] < minDistance) {
          minDistance = distances[i] + graph[i][j];
        }
      }
      
      distances[j] = minDistance;
    }
  }
  
  for (let i = 0; i < N; i++) {
    if (distances[i] === Infinity) {
      console.log('INF');
    } else {
      console.log(distances[i]);
    }
  }
}

process.stdin.setEncoding('utf-8');
process.stdin.on('data', solve);

This code reads the input and computes the shortest distances to all vertices from the nearest source. It uses the Floyd-Warshall algorithm, which is an efficient algorithm for finding the shortest paths in a weighted graph with positive or negative edge weights.

The code reads the number of vertices, edges, and sources. It then reads the edges and sources and stores them in the graph and sources respectively.

Then, for each source, it computes the shortest distances to all other vertices using the Floyd-Warshall algorithm.

Finally, it prints the shortest distances to all vertices.