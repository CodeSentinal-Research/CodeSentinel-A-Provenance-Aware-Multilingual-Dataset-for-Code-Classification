let input = require('fs').readFileSync('/dev/stdin', 'utf8');
let [n] = input.split(" ").map(Number);
let arr = input.split(" ").map(Number);

let oddOccurrence = arr.find((num) => {
    return arr.filter((x) => x === num).length % 2 === 1;
});

console.log(oddOccurrence);