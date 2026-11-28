Here is the JavaScript code for finding the peak element in an array:

const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let arr = [];

rl.question('Enter the size of the array: ', (size) => {
    rl.question('Enter array elements: ', (elements) => {
        arr = elements.split(' ').map(Number);

        const findPeak = (l, r) => {
            const mid = Math.floor((l + r) / 2);
            if ((mid == 0 || arr[mid - 1] <= arr[mid]) && (mid == arr.length - 1 || arr[mid + 1] <= arr[mid])) {
                return mid;
            }
            if (mid > 0 && arr[mid - 1] > arr[mid]) {
                return findPeak(l, mid - 1);
            }
            return findPeak(mid + 1, r);
        }

        console.log('Index of peak element is: ', findPeak(0, arr.length - 1));

        rl.close();
    });
});

In this code, we are using the binary search approach to find the peak element in the array. We first calculate the middle element, then we check if it is the peak element. If it is, we return the index. If not, we recursively call the function for either of the two halves.