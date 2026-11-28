// JavaScript program to find the length of the longest increasing
// subarray using dynamic programming

function longestIncreasingSubarray(arr) {
    if (arr.length === 0) return 0;

    // Initialize maximum length
    let maxLen = 1;

    // Initialize lengths for previous elements
    let prevLen = new Array(arr.length);
    prevLen[0] = 1;

    // Initialize maximum length and end index
    let maxLenEndIndex = 0;

    // Loop through the array and update maxLen, maxLenEndIndex
    for (let i = 1; i < arr.length; i++) {
        prevLen[i] = 1;
        for (let j = 0; j < i; j++) {
            if (arr[i] > arr[j]) {
                prevLen[i] = Math.max(prevLen[i], prevLen[j] + 1);
            }
        }

        // Update maxLen and maxLenEndIndex
        if (prevLen[i] > maxLen) {
            maxLen = prevLen[i];
            maxLenEndIndex = i;
        }
    }

    // Compute length of longest increasing subarray
    let len = maxLen;
    let endIndex = maxLenEndIndex;
    let subarray = [];
    while (len > 0) {
        subarray.push(arr[endIndex]);
        len--;
        endIndex = prevLen[endIndex] ? endIndex - prevLen[endIndex] : 0;
    }

    console.log("Length of longest increasing subarray is " + len);
    console.log("Longest increasing subarray is " + subarray.join(", "));
}

// Test
longestIncreasingSubarray([10, 22, 9, 33, 21, 50, 41, 60, 1]);