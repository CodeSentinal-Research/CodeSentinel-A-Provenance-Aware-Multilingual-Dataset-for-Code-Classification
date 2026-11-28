Here is the JavaScript code for the problem:

const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

let tests = parseInt(rl.readline()); // Number of tests

rl.on('line', function(line) {
  let [N, ...childrenReq] = line.split(' ').map(Number);
  let childrenReqSorted = childrenReq.sort((a, b) => a - b);
  let [M, ...cookieSizes] = rl.readline().split(' ').map(Number);

  let maxSatisfiedChildren = 0;
  let currentCookieSize = 0;
  let currentChildrenReq = 0;

  cookieSizes.sort((a, b) => a - b).forEach((cookieSize) => {
    while (currentChildrenReq < N && currentCookieSize + cookieSize <= childrenReqSorted[currentChildrenReq]) {
      currentCookieSize += cookieSize;
      currentChildrenReq++;
    }

    if (currentCookieSize >= childrenReqSorted[currentChildrenReq]) {
      maxSatisfiedChildren++;
      currentCookieSize = 0;
      currentChildrenReq++;
    }
  });

  console.log(maxSatisfiedChildren);

  if (--tests) {
    rl.pause();
  }
});

rl.close();

This program reads the number of tests from the first line of input. For each test, it reads the number of children and cookie sizes, sorts them, and then iterates over the cookie sizes, adding the smallest cookie size to the current cookie size until the current cookie size + the current cookie size is larger than the next child's requirement. If it is, it increments the count of satisfied children and resets the current cookie size. It prints the number of satisfied children at the end of each test.