Here is the JavaScript code:

function searchMinValue(arr) {
    let minIndex = 0;
    for(let i = 1; i < arr.length; i++) {
        if(arr[i] < arr[minIndex]) {
            minIndex = i;
        }
    }
    return minIndex;
}

In this function, we iterate through the array, and if we find a smaller value than the currently smallest value, we update the `minIndex`. After we've checked all the elements, we return the `minIndex`.

Note: This function assumes that the array is not empty. If the array could be empty, you should add a condition to return `null` or `undefined`.