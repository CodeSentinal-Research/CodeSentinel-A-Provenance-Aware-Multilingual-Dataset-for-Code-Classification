Here is the JavaScript code for the problem:

function sumOfEulerTotient(n) {
    let phi = new Array(n + 1).fill(-1);
    let result = 0;

    for(let i = 1; i <= n; i++) {
        if(phi[i] === -1) {
            if(i % 2 === 0) phi[i] = 2;
            else phi[i] = 2 * i;

            for(let j = i << 1; j <= n; j += i) {
                if(phi[j] === -1) phi[j] = j;
                phi[j] -= phi[i];
            }
        }
        result += phi[i];
    }
    return result;
}

This function calculates the Euler's Totient function for each number from 1 to n, keeping in mind that the Euler's Totient function is defined as the product of all positive integers i that are co-prime (do not share common factors) to i and are less than or equal to i. It calculates the product of all such numbers for each i, then sums up these products.

For example, if n is 7, the function will first calculate the Euler's Totient function for 1, then for 2, and finally for 7. The resulting array will be [1, 2, 4, 3, 6, 8, 10]. The sum of these values is 41.

The time complexity of this function is O(n log log n), which is due to the fact that the Euler's Totient function is a multiplicative function and the prime factorization of each number from 1 to n is a logarithmic function.