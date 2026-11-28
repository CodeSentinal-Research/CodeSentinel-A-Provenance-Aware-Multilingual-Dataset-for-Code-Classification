Here's the JavaScript code that solves the problem:

function isPalindrome(x) {
    if (x < 0 || (x % 10 === 0 && x !== 0)) {
        return false;
    }
    let revertedNumber = 0;
    while (x > revertedNumber) {
        revertedNumber = revertedNumber * 10 + x % 10;
        x = Math.floor(x / 10);
    }
    return x === revertedNumber || x === Math.floor(revertedNumber / 10) * 10 + Math.floor(revertedNumber % 10);
}

This function will return true if the input number is a palindrome, otherwise it will return false. It first checks if the number is less than 0 or if it's divisible by 10 but not 0 (this covers the cases where the number is 0 or negative). Then it starts to build a reverted number and add the last digit of the original number to the reverted number and removes the last digit from the original number until the original number becomes 0 or less. It then compares the reverted number with the original number. If they are equal, it means the original number is a palindrome. If not, it means the original number is not a palindrome.