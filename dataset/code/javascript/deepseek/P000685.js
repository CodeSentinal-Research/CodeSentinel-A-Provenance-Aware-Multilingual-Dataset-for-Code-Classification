Here is the JavaScript solution:

function isPalindrome(s) {
    s = s.toLowerCase();

    // Base case: if the string is empty or has only one character, it's a palindrome.
    if (s.length < 2) {
        return true;
    }

    // Recursive case: check the first and last characters, and the rest of the string.
    if (s.charAt(0) === s.charAt(s.length - 1)) {
        return isPalindrome(s.substring(1, s.length - 1));
    }

    // If the first and last characters do not match, it's not a palindrome.
    return false;
}

// Test the function:
console.log(isPalindrome('racecar'));  // Output: true
console.log(isPalindrome('aibohphobia'));  // Output: false

This function uses a recursive approach to check if a given string is a palindrome. It ignores case, and checks if the string is a palindrome by comparing the first and last characters. If the first and last characters match, it recursively checks the rest of the string (excluding the first and last characters). If the first and last characters do not match, it returns false.