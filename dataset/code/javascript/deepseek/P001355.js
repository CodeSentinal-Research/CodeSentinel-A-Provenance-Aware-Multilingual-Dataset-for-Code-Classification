function constructDistancedSequence(N) {
  let sequence = [N];
  let i = 2;
  let j = 1;
  while (i <= N * 2 - 1) {
    sequence.push(i, i - j);
    i++;
    if (i - j < 2) j++;
  }
  return sequence;
}

let N = prompt("Enter a number between 1 and 20:");
N = parseInt(N);
if (N >= 1 && N <= 20) {
  constructDistancedSequence(N);
} else {
  alert("Invalid input, please enter a number between 1 and 20.");
}