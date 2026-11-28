function findAnagrams(text, pattern) {
    if (text.length < pattern.length) return [];

    let result = [];
    const patternLength = pattern.length;
    const patternCharCount = new Array(26).fill(0);
    const textCharCount = new Array(26).fill(0);

    for (let i = 0; i < patternLength; i++) {
        patternCharCount[pattern.charCodeAt(i) - 'a'.charCodeAt(0)]++;
        textCharCount[text.charCodeAt(i) - 'a'.charCodeAt(0)]++;
    }

    for (let i = 0; i <= text.length - patternLength; i++) {
        if (compareCharCounts(patternCharCount, textCharCount)) {
            result.push(i);
        }

        textCharCount[text.charCodeAt(i) - 'a'.charCodeAt(0)]--;
        textCharCount[text.charCodeAt(i + patternLength) - 'a'.charCodeAt(0)]++;
    }

    return result;
}

function compareCharCounts(counts1, counts2) {
    for (let i = 0; i < 26; i++) {
        if (counts1[i] !== counts2[i]) {
            return false;
        }
    }

    return true;
}

This solution uses a sliding window approach to solve the problem. It first counts the character occurrences in the pattern and text. Then it iterates over the text, sliding a window of size equal to the pattern length, and increments and decrements the count of the current window characters in the character count arrays. If the character counts of the current window are the same as the pattern counts, the index of the window start is added to the result.