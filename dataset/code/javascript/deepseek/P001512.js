// Read input
let [N, Goal] = readline().split(" ").map(Number);
let binArray = readline().split(" ").map(Number);

let count = 0;
let prefixSums = [0];

for (let i = 0; i < N; i++) {
  prefixSums[i + 1] = prefixSums[i] + binArray[i];
}

for (let start = 0; start < N; start++) {
  for (let end = start; end <= N; end++) {
    if (prefixSums[end] - (start > 0 ? prefixSums[start] : 0) === Goal) {
      count++;
    }
  }
}

console.log(count);