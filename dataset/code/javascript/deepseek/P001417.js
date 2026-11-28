Here is the JavaScript code that accomplishes the task:

let input = require('fs').readFileSync('/dev/stdin', 'utf8');
let [N, ...arr1] = input.trim().split(' ').map(Number);
let [M, ...arr2] = input.trim().split(' ').map(Number);

let obj = arr1.reduce((acc, curr) => {
  acc[curr] = (acc[curr] || 0) + 1;
  return acc;
}, {});

let res = [];

for (let num of arr2) {
  if (obj[num]) {
    for (let i = 0; i < obj[num]; i++) {
      res.push(num);
    }
    delete obj[num];
  } else {
    res.push(num);
  }
}

for (let num in obj) {
  for (let i = 0; i < obj[num]; i++) {
    res.push(Number(num));
  }
}

console.log(res.join(' '));

The code uses `reduce` function from JavaScript to count the occurrences of each number in the first array. Then it iterates over the second array and adds the number to the result if it's in the count object and removes it from the count object. At the end, it adds the remaining numbers to the result.