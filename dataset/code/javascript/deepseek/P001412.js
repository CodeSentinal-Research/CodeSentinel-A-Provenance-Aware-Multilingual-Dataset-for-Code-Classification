function countPairsWithGivenDifference(arr, k) {
    let count = 0;
    let set = new Set();
    for (let num of arr) {
        if (set.has(num - k) || set.has(num + k)) {
            count++;
        }
        set.add(num);
    }
    return count;
}

let arr = [1, 5, 3, 4, 2];
let k = 2;
console.log(countPairsWithGivenDifference(arr, k));  // Output: 2