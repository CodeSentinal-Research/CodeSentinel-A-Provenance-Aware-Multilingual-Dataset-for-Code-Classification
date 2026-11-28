function fibonacci(n) {
  if (n === 0) return 0;
  else if (n === 1) return 1;

  let prev = 0;
  let current = 1;

  for (let i = 2; i <= n; i++) {
    let temp = current;
    current += prev;
    prev = temp;
  }

  return current;
}

console.log(fibonacci(Number(process.argv[2])));