Here is the JavaScript code:

function partitionLabels(s) {
    let last = new Array(26).fill(-1);
    for (let i = s.length - 1; i >= 0; i--) {
        last[s.charCodeAt(i) - 97] = i;
    }

    let left = 0;
    let right = 0;
    let ans = [];
    for (let i = 0; i < s.length; i = right) {
        right = Math.max(right, last[s.charCodeAt(i) - 97]);
        ans.push(right - left + 1);
        left = right + 1;
    }

    return ans;
}

console.log(partitionLabels('abab'));

This code works by iterating over the string from right to left. For each character, it finds the last occurrence of that character in the string. It then moves the right pointer to the maximum of the right pointer and the last occurrence of the character, and keeps track of the length of the partition. The result is an array of the lengths of all partitions.

Note: The code assumes that the input string only contains lowercase letters and is at most 26 characters long. If the input string can contain uppercase letters or other characters, you would need to adjust the code accordingly.