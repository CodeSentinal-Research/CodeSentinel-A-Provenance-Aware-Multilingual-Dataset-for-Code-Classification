const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

let cases = 0;
rl.on('line', (line) => {
  if(cases) {
    const [N, target] = line.split(' ').map(Number);
    const arr = line.split(' ').map(Number);

    const plusDfs = (target, idx, sum) => {
      if (idx === N) {
        if (sum === target) {
          console.log(1);
        }
        return;
      }

      if (sum + arr[idx] <= target) {
        plusDfs(target, idx + 1, sum + arr[idx]);
      }

      if (sum - arr[idx] >= 0) {
        plusDfs(target, idx + 1, sum - arr[idx]);
      }
    };

    plusDfs(target, 0, 0);
  } else {
    cases = Number(line);
  }
});

rl.on('close', () => {
  process.stdout.write(`${cases}\n`);
  process.exit();
});