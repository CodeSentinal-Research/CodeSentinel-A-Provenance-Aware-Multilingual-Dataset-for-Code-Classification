Here is the JavaScript code:

function isPerfectSquare(num) {
    if (num < 1 || num > 2147483647) {
        return false;
    }

    let start = 1;
    let end = num;

    while (start <= end) {
        let mid = Math.floor((start + end) / 2);
        let sqr = mid * mid;

        if (sqr === num) {
            return true;
        } else if (sqr < num) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }

    return false;
}
In the given code, we are using binary search to find the perfect square. In each iteration of the while loop, we are finding the middle of the current search range and checking if it's a perfect square. If the square is found, we return true. If not, we move the search range to either the lower half or upper half accordingly.