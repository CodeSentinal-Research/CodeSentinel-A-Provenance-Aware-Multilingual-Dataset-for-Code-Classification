Here's the JavaScript code for the problem:

function searchValue(N, arr, X) {
    // Input validation
    if (N < 1 || N > 100000 || arr.length !== N || arr.find(a => a > X) !== undefined) {
        return -1;
    }

    // Search for the first element smaller than X
    for (let i = 0; i < N; i++) {
        if (arr[i] < X) {
            return i;
        }
    }

    // If no such element is found, return -1
    return -1;
}
In this code, we first check if the input is valid. If not, we return -1 immediately. Then we loop through the array and if we find an element smaller than X, we return its index. If we don't find any such element, we return -1.