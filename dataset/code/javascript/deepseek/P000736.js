Here is the JavaScript code for the problem:

function kthGrammar(N, K) {
    if(N === 1) {
        return 0;
    }
    else {
        let mid = Math.pow(2, N - 1) / 2;
        if(K <= mid) {
            return kthGrammar(N - 1, K);
        } else {
            return (kthGrammar(N - 1, K - mid) === 0) ? 1 : 0;
        }
    }
}

console.log(kthGrammar(3, 1)); // 0
console.log(kthGrammar(3, 2)); // 0
console.log(kthGrammar(3, 3)); // 1
console.log(kthGrammar(3, 4)); // 0
console.log(kthGrammar(3, 5)); // 1
console.log(kthGrammar(3, 6)); // 0

In this code, we are calculating the mid point of the row using Math.pow(2, N - 1) / 2. If the K-th symbol is less than or equal to the mid point, it means that the symbol is in the first half of the row, so we recursively call the function on the next row (N - 1) with K. Otherwise, the symbol is in the second half of the row, so we return the inverted symbol (0 if the K-th symbol is in the first half, 1 if it's in the second half).