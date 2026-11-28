function longestRepeatingCharacterReplacement(str, k) {
    let left = 0, right = 0, maxFreq = 0, maxLength = 0;
    let freqCounts = new Map();

    while (right < str.length) {
        let char = str[right];
        freqCounts.set(char, (freqCounts.get(char) || 0) + 1);
        maxFreq = Math.max(maxFreq, freqCounts.get(char));

        while ((right - left + 1 - maxFreq) > k) {
            let leftChar = str[left];
            freqCounts.set(leftChar, freqCounts.get(leftChar) - 1);
            maxFreq = Math.max(...freqCounts.values());
            left++;
        }

        maxLength = Math.max(maxLength, right - left + 1);
        right++;
    }

    return maxLength;
}