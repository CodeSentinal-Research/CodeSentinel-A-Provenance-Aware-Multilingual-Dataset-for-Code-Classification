function longestRepeatingCharacterReplacement(S, K) {
    let left = 0;
    let right = 0;
    let maxFreq = 0;
    let maxLength = 0;
    let charFreq = new Map();

    for (right = 0; right < S.length; right++) {
        charFreq.set(S[right], (charFreq.get(S[right]) || 0) + 1);
        maxFreq = Math.max(maxFreq, charFreq.get(S[right]));

        while (right - left + 1 - maxFreq > K) {
            charFreq.set(S[left], charFreq.get(S[left]) - 1);
            maxFreq = Math.max(...charFreq.values());
            left++;
        }

        maxLength = Math.max(maxLength, right - left + 1);
    }

    return maxLength;
}