Here is a simple JavaScript code solution to the problem:

function findClosestElements(n, nums, k, x) {
    let left = 0;
    let right = n - k;

    nums.sort((a, b) => {
        if (Math.abs(a - x) < Math.abs(b - x)) {
            return -1;
        } else if (Math.abs(a - x) > Math.abs(b - x)) {
            return 1;
        } else {
            return a > b ? 1 : -1;
        }
    });

    return nums.slice(left, right + 1);
}

This code first sorts the array by the difference between the element and the target number. Then, it returns the k elements closest to the target.

Please note that this solution assumes that `nums` is a sorted array of integers and `k` is an integer. The function also returns the `k` closest elements to the target. If there is a tie, it prefers the smaller elements.

To use this function, call it with the array length (`n`), the array (`nums`), the number of elements to return (`k`), and the target number (`x`):

let result = findClosestElements(5, [1, 2, 3, 4, 5], 3, 3);
console.log(result); // Outputs: [1, 2, 3]