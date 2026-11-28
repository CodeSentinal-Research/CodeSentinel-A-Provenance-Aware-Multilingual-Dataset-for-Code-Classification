function isPalindrome(str) {
    var len = str.length;
    for (var i = 0; i < len/2; i++) {
        if (str[i] !== str[len-1-i]) {
            return "No";
        }
    }
    return "Yes";
}

// Testing the function
console.log(isPalindrome("madam")); // Expected output: Yes
console.log(isPalindrome("hello")); // Expected output: No