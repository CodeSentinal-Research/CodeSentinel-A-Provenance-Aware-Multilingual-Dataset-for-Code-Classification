Here's the JavaScript solution for the given problem:

function distinctPrimeFactors(n) {
    let factors = [];
    for(let i = 2; i <= n; i++) {
        while(n % i == 0) {
            factors.push(i);
            n /= i;
        }
    }
    return factors;
}

This function works by iterating over the numbers 2 through N (inclusive), and for each number, it checks if the number is a factor of N. If it is, it adds the number to the factors array and divides N by the number. This process continues until N is no longer a factor of the number.

However, this function has a time complexity of O(N), which can be slow for large N. A more efficient solution would be to find all prime factors of N first, and then find the distinct prime factors. Here's how you can do it:

function distinctPrimeFactors(n) {
    if (n <= 1) return [];
    let factors = [];
    for (let i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            factors.push(i);
            n /= i;
        }
    }
    if (n > 1) factors.push(n);
    return [...new Set(factors)]; // remove duplicates
}

This function first handles the base case for small numbers, then it finds all prime factors by dividing N by each number from 2 up to sqrt(N). If N is still greater than 1 after the loop, it adds N to the factors array. Finally, it returns the factors array with duplicates removed by converting it to a Set (which only allows unique values) and then back to an array.