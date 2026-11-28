// Function to check if change can be given
function lemonadeChange(N, customers) {
    let notes = {5: 0, 10: 0, 20: 0};

    // Count the notes
    customers.forEach(function(payment) {
        notes[payment]++;
    });

    // Check if change can be given
    return (notes[5] > 0 && notes[10] > 0 && notes[20] > 0) 
        || (notes[5] > 1 && notes[10] > 1 && notes[20] > 1)
        || (notes[5] > 2 && notes[10] > 2 && notes[20] > 2);
}

// Test cases
console.log(lemonadeChange(3, [5, 5, 20])); // Output: YES
console.log(lemonadeChange(3, [5, 10, 20])); // Output: NO