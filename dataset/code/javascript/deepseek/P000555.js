Here is the JavaScript code for the problem:

function minReverseOperations(n, p, b, k) {
  if (b.includes(p)) {
    return -1;
  }

  const operations = new Array(n).fill(-1);
  operations[p] = 0;

  const queue = [[p, 0]];

  while (queue.length) {
    const [i, j] = queue.shift();

    if (i - k + 1 >= 0 && operations[i - k + 1] === -1) {
      operations[i - k + 1] = j + 1;
      queue.push([i - k + 1, j + 1]);
    }

    if (i + k < n && operations[i + k] === -1) {
      operations[i + k] = j + 1;
      queue.push([i + k, j + 1]);
    }
  }

  return operations;
}

This JavaScript function `minReverseOperations` takes in five parameters: the size of the array `n`, the starting index `p`, an array `b` of banned indices, and the length of the subarray `k`. It first checks if `p` is in `b`. If it is, it returns `-1`. If not, it initializes an array `operations` of size `n` filled with `-1`. `operations[p]` is set to `0` because the operation needed to reach the initial position is `0`.

The function then creates a queue and pushes the starting index `p` and the number of operations needed `0` to it.

It then enters a loop that continues until the queue is empty. Inside the loop, it takes the first element `i` from the queue and checks if reversing `i` by `k` positions can be done. If it can, it updates `operations[i - k + 1]` and `operations[i + k]` to the current number of operations plus `1`. It also pushes `i - k + 1` and `i + k` to the queue.

Finally, it returns `operations`.