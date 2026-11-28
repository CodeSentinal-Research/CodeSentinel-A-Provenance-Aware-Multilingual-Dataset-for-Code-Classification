Here is the JavaScript code to solve the problem:

function longestRepeatingCharacterReplacement(S, K) {
    let left = 0;
    let right = 0;
    let count = new Map();
    let maxCount = 0;
    let maxLength = 0;
    for (right in S) {
        if (count.has(S[right])) {
            count.set(S[right], count.get(S[right]) + 1);
        } else {
            count.set(S[right], 1);
        }
        maxCount = Math.max(maxCount, count.get(S[right]));
        while (right - left + 1 - maxCount > K) {
            count.set(S[left], count.get(S[left]) - 1);
            left++;
        }
        maxLength = Math.max(maxLength, right - left + 1);
    }
    return maxLength;
}

// Example usage:
console.log(longestRepeatingCharacterReplacement("ABAB", 2)); // 4
console.log(longestRepeatingCharacterReplacement("AABABBA", 1)); // 5
This code creates a sliding window that moves from left to right in the string. For each character, it updates the count of the character and checks if it is in the window. If it is, it increments the count of the character. If not, it adds the character to the count map. It also updates the maxCount and maxLength.

The window moves from left to right, so it's checking if the length of the window (right - left + 1) is greater than the maxCount (the number of times the max count character appears in the window). If it is, it moves the left pointer one step to the right.

Finally, it returns the maxLength, which is the length of the longest substring that can be obtained by replacing at most K characters.