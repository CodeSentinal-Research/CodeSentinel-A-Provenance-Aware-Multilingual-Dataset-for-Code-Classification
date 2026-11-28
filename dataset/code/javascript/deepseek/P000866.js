Here is the JavaScript code that solves the problem:

const solve = (nums, q) => {
    const n = nums.length;
    let prefixXOR = new Array(n + 1).fill(0);
    for (let i = 1; i <= n; i++) {
        prefixXOR[i] = prefixXOR[i - 1] ^ nums[i - 1];
    }

    let answer = [];
    for (let i = 0; i < q; i++) {
        let { L, R } = q[i];
        answer.push(prefixXOR[R] ^ prefixXOR[L - 1]);
    }

    return answer;
}

// Testing the function
let nums = [1, 3, 2, 7, 5, 4, 8, 6];
let q = [{L: 1, R: 3}, {L: 2, R: 5}, {L: 1, R: 5}];
console.log(solve(nums, q)); // [8, 11, 5]

In this code, we first create a prefix XOR array, then for each query, we calculate the XOR of the elements in the range from L to R (both inclusive) and add it to the answer array.