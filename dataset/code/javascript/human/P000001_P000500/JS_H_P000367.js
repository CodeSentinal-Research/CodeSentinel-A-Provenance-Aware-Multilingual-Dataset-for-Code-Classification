import { Vertex } from "./Vertex.js";

function knightMoves(start, end) {
  //=== use array destructuring to collect values into individual variables
  const [startX, startY] = start;
  const [endX, endY] = end;

  //=== check that argument coordinate ranges are valid
  const isValid = [startX, startY, endX, endY].every(
    (coord) => coord >= 0 && coord <= 7
  );
  if (!isValid) {
    throw new Error("Coordinates must be between 0 and 7.");
  }

  //=== instantiate start and end vertex nodes given by the user
  const startVertex = new Vertex(startX, startY);
  const endVertex = new Vertex(endX, endY);

  //=== generate next move list (edges)
  function possibleMoves(currentVertex) {
    // all 8 possible moves for the knight, (change in x, change in y)
    const moveSet = [
      [-2, -1],
      [-2, 1],
      [-1, -2],
      [-1, 2],
      [2, -1],
      [2, 1],
      [1, -2],
      [1, 2],
    ];

    // queue to keep track of the next possible positions
    const possibleNextVertices = [];

    for (const [dx, dy] of moveSet) {
      const newX = currentVertex.x + dx;
      const newY = currentVertex.y + dy;

      //filter out any next moves that would go off the board
      const isValid = [newX, newY].every((coord) => coord >= 0 && coord <= 7);
      if (!isValid) continue;

      const newVertex = new Vertex(newX, newY, currentVertex);
      possibleNextVertices.push(newVertex);
    }
    return possibleNextVertices;
  }

  //=== algorithmic search for shortest path using BFS
  function search(startVertex, endVertex) {
    // initialize the queue with the starting position
    let queue = [startVertex];
    // set to keep track of visited positions (as "x,y" strings)
    let visited = new Set();
    visited.add(`${startVertex.x},${startVertex.y}`);

    // continue searching while there are positions to explore
    while (queue.length) {
      // dequeue the next position to explore
      let frontValue = queue.shift();
      // if we've reached the end position, reconstruct and return the path
      if (frontValue.x === endVertex.x && frontValue.y === endVertex.y) {
        let finalPath = [];
        let current = frontValue;
        // follow parent links back to the start, building the path in reverse
        while (current) {
          finalPath.unshift(current);
          current = current.parent;
        }
        // return the shortest path
        return finalPath;
      }
      // for each valid knight move from the current position
      for (const move of possibleMoves(frontValue)) {
        const key = `${move.x},${move.y}`;
        // if this position hasn't been visited yet
        if (!visited.has(key)) {
          // mark as visited
          visited.add(key);
          // enqueue for further explorations
          queue.push(move);
        }
      }
    }
  }

  // run search within knightMoves on the instantiated argument values (objects)
  const path = search(startVertex, endVertex);
  // log the results
  console.log(`=> You made it in ${path.length - 1} moves! Here's your path:`);
  path.forEach((v) => console.log(`[${v.x}, ${v.y}]`));
}

// test call of function
knightMoves([3, 3], [0, 0]);
