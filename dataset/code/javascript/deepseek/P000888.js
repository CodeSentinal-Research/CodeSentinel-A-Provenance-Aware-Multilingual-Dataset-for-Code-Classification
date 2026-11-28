Here is the JavaScript code to solve the problem:

function isAutomorphic(N) {
    // Convert the number to a string and remove the '0' prefix
    let str = N.toString().replace(/^0+/, '');
    // Square the number
    let squared = N * N;
    // Check if the square ends with the same digits as the number itself
    return str === squared.toString().slice(-str.length);
}
In this code, we first convert the input number to a string and remove any leading zeroes. We then square the number and check if the square ends with the same digits as the number itself by comparing the last part of the square (which is a string) with the first part of the number (which is a number). If they are equal, then the number is an Automorphic number.