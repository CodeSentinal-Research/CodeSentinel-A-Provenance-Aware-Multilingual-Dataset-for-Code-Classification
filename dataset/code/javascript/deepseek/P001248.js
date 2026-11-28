Here's the JavaScript code that solves the problem:

// Read input
let [N, limit] = readline().split(' ').map(Number);
let weights = readline().split(' ').map(Number);

// Initialize counter
let count = 0;

// Sort weights in ascending order
weights.sort((a, b) => a - b);

// Iterate over weights
for (let i = 0; i < N; i++) {
  // If the current weight is greater than the limit,
  // increment the counter and consider the next weight
  if (weights[i] > limit) {
    count++;
  }
  // If the current weight is less than or equal to the limit,
  // consider the next weight, regardless of its value
  else {
    i++;
    count++;
  }
}

// Print the minimum number of boats
console.log(count);

In this code, we first read the number of people and the maximum weight each boat can carry. Next, we sort the weights in ascending order. We then iterate over the sorted weights, and for each weight, we check if it is greater than the limit. If it is, we increment the counter. If it is not, we consider the next weight. At the end, we print the minimum number of boats.