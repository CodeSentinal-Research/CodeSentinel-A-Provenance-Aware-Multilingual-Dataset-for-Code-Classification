Here is the JavaScript code for the problem:

function validPalindrome(s) {
    let i = 0, j = s.length - 1;
    while (i < j) {
        if (s[i] !== s[j]) {
            return s.substring(i + 1, j + 1) === s.substring(i, j) ||
                s.substring(i, j) === s.substring(i + 1, j + 1);
        }
        i++;
        j--;
    }
    return true;
}

In this function, we use two pointers, one at the start of the string and the other at the end. We iterate through the string, comparing the characters at the current pointers. If they are not equal, we check if removing one character between the current pointers and the end of the string makes the string a palindrome. If it does, we return true. If it doesn't, we continue to the next character. If we iterate through the whole string and find no mismatched characters, we return true.