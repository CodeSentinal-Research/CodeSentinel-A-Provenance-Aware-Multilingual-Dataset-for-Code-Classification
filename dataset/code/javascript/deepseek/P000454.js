function findPages(N, M) {
  if(M > N) {
    throw new Error('M must be less than or equal to N');
  }

  let min = Math.min(N, M);
  let max = Math.max(N, M);
  let result = (max - min) + min;

  return result;
}

function solve(input) {
  let [N, M] = input[0].split(' ').map(Number);
  let books = input[1].split(' ').map(Number);

  if(M > N) {
    throw new Error('M must be less than or equal to N');
  }

  books.sort((a, b) => a - b);

  let [left, right] = [0, 0];
  while(left < right) {
    let mid = Math.floor((right + left) / 2);
    let count = books.reduce((acc, curr) => acc + Math.floor(curr / (mid + 1)), 0);
    if(count < M) {
      left = mid + 1;
    } else {
      right = mid;
    }
  }

  return left;
}

console.log(solve(["4 2", "10 10 10 10"])); // 15
console.log(solve(["5 1", "5 5 5 5 5"])); // 5
console.log(solve(["3 3", "1 2 3"])); // 2
console.log(solve(["4 2", "10 10 10 10 10"])); // 50