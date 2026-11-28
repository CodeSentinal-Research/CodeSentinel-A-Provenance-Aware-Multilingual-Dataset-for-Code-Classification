function countSubarrays(N, K, A) {
    let count = 0;
    for (let i = 0; i < N; i++) {
        let sum = A[i];
        if (sum === K) {
            count++;
        }
        for (let j = i + 1; j < N; j++) {
            sum += A[j];
            if (sum === K) {
                count++;
            }
        }
    }
    return count;
}