let input = process.argv[2];

function countPalindromicSubstrings(s) {
    let count = 0;
    let len = s.length;

    for (let i = 0; i < len; i++) {
        for (let j = i + 1; j <= len; j++) {
            let substring = s.slice(i, j);
            if (substring === substring.split('').reverse().join('')) {
                count++;
            }
        }
    }

    return count;
}

console.log(countPalindromicSubstrings(input));
This JavaScript function will count the palindromic substrings in a given string. It does this by iterating through each character in the string and creating a substring that includes all characters before the current character. Then it checks if this substring is the same when reversed (i.e., it is a palindrome). If it is, it increments a counter. The function finally returns the total count of palindromic substrings.

This function uses a brute force approach and can be slow for large strings.

To handle large strings, you might want to use dynamic programming or a more efficient algorithm.