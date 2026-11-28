Here is a basic implementation of Dijkstra's algorithm for shortest path in a graph using JavaScript:

function solve() {
    let [N, M, S] = readline();
    let graph = new Map();
    let distances = Array(N + 1).fill(Infinity);
    distances[S] = 0;

    for(let i = 0; i < M; i++) {
        let [u, v, w] = readline();
        if(!graph.has(u)) graph.set(u, []);
        graph.get(u).push({v, w});
    }

    let pq = new PriorityQueue((a, b) => distances[a] - distances[b], [], N);
    pq.enqueue(S);

    while(pq.length) {
        let u = pq.dequeue();
        for(let {v, w} of graph.get(u)) {
            if(distances[v] > distances[u] + w) {
                distances[v] = distances[u] + w;
                pq.enqueue(v);
            }
        }
    }

    for(let i = 1; i <= N; i++) {
        if(i !== S) {
            console.log(distances[i] === Infinity ? -1 : distances[i]);
        }
    }
}

This code uses a priority queue to keep track of the nodes that need to be processed next. The queue is sorted by the distance from the source. The `dequeue` operation is used to remove the node with the smallest distance from the queue. The process repeats until the queue is empty.

The time complexity is O(E log E) because each edge is processed once, and each insertion to the priority queue and each removal from the priority queue takes logarithmic time. The space complexity is O(N + E) because there are additional space for the distance array and the priority queue.

Please note that this code does not handle the input data correctly. In a real-world situation, you would want to read the input data line by line and parse each line into the appropriate data types. Additionally, you would need to implement the `readline` function which is not provided in this example. The `readline` function would read the input data line by line and return an array of values.