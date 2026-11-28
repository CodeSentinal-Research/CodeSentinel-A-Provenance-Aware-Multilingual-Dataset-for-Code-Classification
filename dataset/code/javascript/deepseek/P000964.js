Here is the JavaScript code for solving Chinese Remainder Theorem:

function chineseRemainder(N, remainders, moduli) {
    let product = 1;
    for (let i = 0; i < N; i++) {
        product *= moduli[i];
    }

    let s = 0;
    for (let i = 0; i < N; i++) {
        let r = product / moduli[i];
        s += remainders[i] * r * product;
    }

    return s % product;
}

// Testing the function
console.log(chineseRemainder(3, [2, 3, 1], [3, 5, 7]));

This function works by calculating the product of all moduli, then for each remainder, it finds the value of r such that r % moduli[i] = 0, and finally returns s % product.

Please note that this function assumes that all moduli are pairwise coprime. If they are not, the function may not give the correct result.