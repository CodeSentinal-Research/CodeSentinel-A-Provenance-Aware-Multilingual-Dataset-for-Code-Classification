Here is the JavaScript code for the given problem:

function binaryWatch(num) {
    let res = [];
    for (let h = 0; h < 12; h++) {
        for (let m = 0; m < 60; m++) {
            if ((h.toString(2).length + m.toString(2).length) === num + 1 ? res.push(`${h}:${m < 10 ? '0' + m : m}`) : '';
        }
    }
    return res;
}
console.log(binaryWatch(1)); // 2^1 = 2
console.log(binaryWatch(2)); // 2^2 = 4
console.log(binaryWatch(3)); // 2^3 = 8
console.log(binaryWatch(4)); // 2^4 = 16

The code first creates an empty array res, and then iterates through all possible combinations of hours and minutes (both from 0 to 11 and from 0 to 59) using two loops. For each combination, it checks if the binary representation of hours and minutes have the same length. If they do, it adds the time to the result array. The `toString(2)` method converts a number to binary and then counts the length of the binary representation of the number. The `+` operator is used to concatenate the string representations of hours and minutes.