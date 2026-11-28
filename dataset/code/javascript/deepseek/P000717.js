Here is the JavaScript code that solves the problem:

function partition(str, start, end) {
    if(start >= end) {
        return [str];
    }
    let result = [];
    for(let i = start; i < end; i++) {
        if(isPalindrome(str, start, i)) {
            let partitions = partition(str, i+1, end);
            for(let partition of partitions) {
                result.push([str.substring(start, i+1), ...partition]);
            }
        }
    }
    return result;
}

function isPalindrome(str, start, end) {
    while(start < end) {
        if(str[start] !== str[end]) {
            return false;
        }
        start++;
        end--;
    }
    return true;
}

function findPalindromePartitions(str) {
    return partition(str, 0, str.length);
}

// Test with the example string
console.log(findPalindromePartitions('racecar'));

This code uses recursion and dynamic programming to find all possible palindrome partitions. The `partition` function is a recursive function that partitions the given string into palindrome partitions. It takes a string, the start index, and the end index of the substring to be partitioned.

The `isPalindrome` function checks if a given substring is a palindrome. It does this by comparing the first and last characters, and then the second and penultimate characters, and so on, until it finds a mismatch or until it has checked all characters. If it finds a mismatch, it returns false. If it checks all characters and has not found a mismatch, it returns true.

The `findPalindromePartitions` function is the main function that starts the partition process. It calls the `partition` function with the start index of the string and the end index of the string.

Finally, the code tests the `findPalindromePartitions` function with the string 'racecar'. The result is an array of arrays, where each inner array represents a valid palindrome partition.