function countWindows(N, K, D, arr) {
    // Initialize count variable
    let count = 0;

    // Loop through array
    for (let i = 0; i < N; i++) {
        // Calculate sum of current window
        let sum = 0;
        for (let j = i; j < i + K; j++) {
            sum += arr[j];
        }

        // Check if sum is divisible by D
        if (sum % D === 0) {
            count++;
        }
    }

    // Return count
    return count;
}