function solve() {
  const fs = require('fs');
  const stdin = process.stdin;
  const stdout = process.stdout;

  stdin.pipe(fs.createWriteStream('input.txt'));
  fs.createReadStream('output.txt').pipe(stdout);

  process.stdin.on('end', () => {
    process.exit();
  });
}

setTimeout(solve, 10000);