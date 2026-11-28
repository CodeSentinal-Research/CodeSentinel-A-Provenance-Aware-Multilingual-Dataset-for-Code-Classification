function canWinNim(n) {
    // Base case: if n is a multiple of 4, then the last player will lose
    if (n % 4 === 0) {
        return false;
    } else {
        // If n is not a multiple of 4, then the first player will win
        return true;
    }
}

// Testing the function with a few cases
console.log(canWinNim(1)); // False
console.log(canWinNim(2)); // True
console.log(canWinNim(3)); // False
console.log(canWinNim(4)); // False
console.log(canWinNim(5)); // True
This function takes in an integer N as input and returns a boolean value based on the Nim game rules. If N is a multiple of 4, then the last player will lose (i.e., return false), otherwise, the first player will win (i.e., return true).