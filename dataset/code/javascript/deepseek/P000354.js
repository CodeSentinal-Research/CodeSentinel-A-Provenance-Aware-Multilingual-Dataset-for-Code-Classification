function countOccurrences(N, arr, X) {
    // Check if the input is valid
    if (!Array.isArray(arr) || arr.length !== N || typeof X !== 'number') {
        throw new Error('Invalid input');
    }

    // Count the occurrences
    let count = 0;
    for (let i = 0; i < N; i++) {
        if (arr[i] === X) {
            count++;
        }
    }
    return count;
}