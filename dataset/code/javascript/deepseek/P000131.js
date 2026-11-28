Here is a JavaScript solution for the problem:

let input = process.stdin;
input.setEncoding('utf8');

input.on('data', (line) => {
  let [N, ...arr] = line.split(' ').map(Number);
  if (N < 1 || N > 1000) throw new Error('Invalid input');
  let rightMax = new Array(N).fill(-1);
  let leaders = [];

  (new Array(N)).fill(0).forEach((_, i) => {
    let j = N - i - 1;
    if (i > 0) rightMax[i] = Math.max(rightMax[i], rightMax[i-1]);
    if (j < N - 1) rightMax[j] = Math.max(rightMax[j], rightMax[j+1]);
    if (arr[i] > rightMax[j]) {
      leaders.push(arr[i]);
    }
  });

  console.log(leaders.join(' '));
});

In this solution, we use an auxiliary array `rightMax` to store the maximum element to its right for each index. The maximum element to its right for an index is either the maximum element to its right (if it exists) or the maximum element to the left (if it exists). We then iterate over the array from left to right, updating `rightMax` as we go. If the current element is greater than the maximum element to its right, it is a leader and we add it to our result array.

Please note that this solution assumes that the array and input are separated by a newline character.