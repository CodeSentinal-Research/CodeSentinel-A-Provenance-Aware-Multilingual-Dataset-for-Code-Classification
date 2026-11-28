function findFirstOdd(N, array) {
    for(let i = 0; i < N; i++) {
        if(array[i] % 2 !== 0) {
            return i;
        }
    }
    return -1;
}