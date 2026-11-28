function canSplit(s) {
    // Convert the string into an array of digits
    let digits = Array.from(s, Number);
    
    // Loop through the digits
    for (let i = 0; i < digits.length - 1; i++) {
        // If the current digit is greater than or equal to the next one
        if (digits[i] >= digits[i + 1]) {
            // Return false
            return false;
        }
    }
    
    // If the loop finishes without returning false, return true
    return true;
}