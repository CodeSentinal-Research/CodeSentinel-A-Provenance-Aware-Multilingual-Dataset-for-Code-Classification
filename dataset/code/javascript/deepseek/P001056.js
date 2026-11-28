Here is a JavaScript solution that meets the requirements:

class SmallestInfiniteSet {
  constructor() {
    this.nums = new Set([...Array(20000).keys()]);
    this.added = new Set();
    this.removed = new Set();
  }

  add(num) {
    this.removed.delete(num);
    this.added.add(num);
    this.nums.delete(num);
  }

  remove(num) {
    if (this.added.has(num)) {
      this.added.delete(num);
      this.removed.add(num);
    } else if (this.nums.has(num)) {
      this.removed.delete(num);
      this.nums.delete(num);
    }
  }

  smallest() {
    if (this.removed.size > 0) {
      const num = [...this.removed][0];
      this.removed.delete(num);
      return num;
    }
    return [...this.nums][0];
  }
}

function main() {
  const SIS = new SmallestInfiniteSet();
  const fs = require('fs');
  process.stdin.setEncoding('utf-8');
  let inputString = '';
  process.stdin.on('data', (inputStdinBuffer) => {
    inputString += inputStdinBuffer;
  });
  process.stdin.on('end', () => {
    inputString = inputString.trim();
    const inputs = inputString.split('\n');
    const Q = parseInt(inputs[0]);
    for (let i = 1; i <= Q; i++) {
      const op = inputs[i];
      const operation = op.split(' ')[0];
      const num = parseInt(op.split(' ')[1]);
      if (operation === 'add') {
        SIS.add(num);
      } else if (operation === 'remove') {
        SIS.remove(num);
      }
      console.log(SIS.smallest());
    }
  });
}

main();

In this code, we use a set for the numbers that have not been removed and removed, and a set for the numbers that have been removed. When a number is added, it is added to the set of removed numbers and removed from the set of not removed numbers. When a number is removed, it is removed from the set of not removed numbers and added to the set of removed numbers. The smallest number in the set of not removed numbers is the smallest number that can be removed or added.