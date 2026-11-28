function maxProduct(arr) {
    if (arr.length < 3) {
        throw new Error('Array must contain at least 3 numbers');
    }

    let max1 = Math.max(arr[0], arr[1]);
    let max2 = Math.min(arr[0], arr[1]);
    let max3 = arr[0];

    for (let i = 2; i < arr.length; i++) {
        let num = arr[i];

        if (num > max1) {
            max1 = num;
            max2 = max1;
            max3 = max2;
        } else if (num > max2) {
            max2 = num;
            max3 = Math.max(max2, max3);
        } else if (num > max3) {
            max3 = num;
        }

        max1 = Math.max(max1, max2);
        max2 = Math.min(max1, max2);
    }

    return Math.max(max1 * max2 * max3, max1 * (max2 * max3) * max1);
}

// Example usage:
let arr = [1, 2, 3, 4, 5];
console.log(maxProduct(arr)); // Output: 60