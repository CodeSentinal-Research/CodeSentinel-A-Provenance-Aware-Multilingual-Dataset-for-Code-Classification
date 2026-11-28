Here is the JavaScript code:

let [N, ...a] = readline().split(" ").map(Number);
let [M, ...b] = readline().split(" ").map(Number);

let mergedArray = [...a, ...b].sort((a, b) => a - b);

console.log(mergedArray.join(" "));

In this code, we first read the number of elements in each array and then read the elements of both arrays. We then merge the two arrays and sort the merged array in ascending order. Finally, we print the sorted array.