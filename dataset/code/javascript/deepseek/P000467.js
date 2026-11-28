// Read the input size of the two arrays
let [M, N] = process.argv[2].split(' ').map(Number);
let arr1 = process.argv[3].split(' ').map(Number);
let arr2 = process.argv[4].split(' ').map(Number);

function findMedianSortedArrays(arr1, arr2) {
    let mergedArray = [...arr1, ...arr2];
    mergedArray.sort((a, b) => a - b);

    let median;
    if (M % 2 === 1) {
        median = mergedArray[Math.floor(M / 2)];
    } else {
        let lower = mergedArray[M / 2 - 1];
        let upper = mergedArray[M / 2];
        median = (lower + upper) / 2;
    }

    return median;
}

console.log(findMedianSortedArrays(arr1, arr2));

This JavaScript code reads the size of the two arrays and their contents from the command line arguments. The `findMedianSortedArrays` function combines the two arrays, sorts them, and calculates the median based on whether the size of the array is odd or even. If the size is odd, it returns the middle element. If the size is even, it returns the average of the two middle elements.

You can run this program from the command line with the following command:

node medianOfTwoArrays.js M N arr1 arr2

Replace `M`, `N`, and `arr1 arr2` with your values.