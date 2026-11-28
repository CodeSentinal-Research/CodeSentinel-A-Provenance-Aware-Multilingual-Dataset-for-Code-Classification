let [M, N] = readline().split(' ').map(Number);
let arr1 = readline().split(' ').map(Number);
let arr2 = readline().split(' ').map(Number);

let intersection = arr1.filter(value => arr2.includes(value));
console.log(intersection);