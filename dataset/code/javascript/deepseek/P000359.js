Here is the JavaScript code:

function searchPositive(N, arr) {
    for (let i = 0; i < N; i++) {
        if (arr[i] > 0) {
            return i;
        }
    }
    return -1;
}

This function will iterate through the input array, and return the index of the first positive number it encounters. If no positive number is found, it will return -1. The time complexity of this function is O(N), where N is the length of the input array.