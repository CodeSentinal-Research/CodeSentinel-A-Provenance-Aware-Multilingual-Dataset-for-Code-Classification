function calculateBill(units) {
    if(units < 0 || units > 1000) {
        console.log("Invalid input. Please enter a non-negative integer between 0 and 1000.");
        return;
    }

    let bill;

    if(units <= 50) {
        bill = units * 0.5;
    } else if(units <= 100) {
        bill = 50 * 0.5 + (units - 50) * 1;
    } else if(units <= 200) {
        bill = 50 * 0.5 + 50 * 1 + (units - 100) * 1.5;
    } else {
        bill = 50 * 0.5 + 50 * 1 + 100 * 1.5 + (units - 200) * 2;
    }

    return bill;
}
This JavaScript function will calculate the electricity bill based on the units consumed. It first checks if the input units is within the valid range (0 to 1000). If it's not, it outputs an error message and returns.

Then, it calculates the bill based on the units consumed. The basic formula for calculating the bill is units * unit_price. If the units consumed is less than 50, the bill is the units * 0.5. If the units consumed is 50 or more but less than 100, the bill is 50 * 0.5 + (units - 50) * 1. If the units consumed is 100 or more but less than 200, the bill is 50 * 0.5 + 50 * 1 + (units - 100) * 1.5. For units 200 or more, the bill is 50 * 0.5 + 50 * 1 + 100 * 1.5 + (units - 200) * 2.

Finally, it returns the bill amount.