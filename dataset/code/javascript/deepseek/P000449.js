Here's the JavaScript solution for the problem:

function isPerfectSquare(n) {
    if (n < 1 || n > 10^9) {
        console.log("Invalid input");
        return;
    }

    let start = 1;
    let end = n;

    while (start <= end) {
        let mid = Math.floor((start + end) / 2);
        let sqr = mid * mid;

        if (sqr === n) {
            console.log("Yes");
            return;
        } else if (sqr < n) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }

    console.log("No");
}

// Test the function
isPerfectSquare(16);
isPerfectSquare(20);
isPerfectSquare(1);
isPerfectSquare(10^9);
isPerfectSquare(-1);

This function works by performing a binary search to find the square root of the input number. If the square of the mid point is equal to the input number, then the input number is a perfect square. If not, it adjusts the search range accordingly.

Note: The function will exit and print "No" if the input number is not a perfect square.