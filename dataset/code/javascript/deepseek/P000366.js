Here is the JavaScript code:

function findMaxIndex(arr) {
    if (!Array.isArray(arr) || arr.length === 0) {
        return 'Invalid input';
    }
    let maxIndex = 0;
    for (let i = 1; i < arr.length; i++) {
        if (arr[i] > arr[maxIndex]) {
            maxIndex = i;
        }
    }
    return maxIndex;
}
This function takes an array as an argument and returns the index of the maximum value in the array. If the array is empty or not provided as an argument, the function returns 'Invalid input'.