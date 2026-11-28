Here is the JavaScript code:

function totalHammingDistance(nums) {
    let total = 0;
    for (let i = 0; i < nums.length; i++) {
        for (let j = i + 1; j < nums.length; j++) {
            total += hammingDistance(nums[i], nums[j]);
        }
    }
    return total;
}

function hammingDistance(x, y) {
    let diff = x ^ y;
    let distance = 0;
    while (diff) {
        diff >>= 1;
        distance += diff;
    }
    return distance;
}

In this code, we first define a function `totalHammingDistance` that takes in an array of integers and calculates the sum of Hamming distances between every pair of elements.

The `hammingDistance` function calculates the Hamming distance between two integers. It does this by XORing the two integers and then right-shifting the result by one bit (since the Hamming distance between two bits is the number of different bits between the two integers). We do this for each pair of bits and accumulate the total distance.

Note that in JavaScript, the bitwise AND operator `&` is used to compare two bits (`x & y`). This returns a bit where a set bit is present in both `x` and `y` and a clear bit in one or both.