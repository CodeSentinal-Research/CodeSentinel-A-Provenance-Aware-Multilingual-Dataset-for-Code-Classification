Here is a simple JavaScript solution for the problem:

process.stdin.setEncoding('utf8');
process.stdin.on('data', function(input) {
    let [str, k] = input.split('\n');
    k = parseInt(k);
    console.log(longestSubstring(str, k));
});

function longestSubstring(str, k) {
    let maxFreqChar = getMaxFrequencyChar(str);
    if (str.length - maxFreqChar.freq > k) {
        return str.length;
    } else if (str.length - maxFreqChar.freq + maxFreqChar.index > k) {
        return str.length - maxFreqChar.freq + maxFreqChar.index;
    } else {
        return str.length - maxFreqChar.freq;
    }
}

function getMaxFrequencyChar(str) {
    let map = new Map();
    for (let i = 0; i < str.length; i++) {
        if (map.has(str[i])) {
            map.set(str[i], map.get(str[i]) + 1);
        } else {
            map.set(str[i], 1);
        }
    }
    let maxFreqChar = {char: '', freq: 0};
    for (let [char, freq] of map.entries()) {
        if (freq > maxFreqChar.freq) {
            maxFreqChar = {char: char, freq: freq};
        }
    }
    return maxFreqChar;
}

This code reads a line of input from stdin, splits it into the string and the number of replacements, and then calls the `longestSubstring` function with these values. The `longestSubstring` function determines the maximum length of the string that can be made by replacing at most K characters. The `getMaxFrequencyChar` function finds the character with the highest frequency in the string. If the length of the string minus the frequency of the max frequency character is greater than K, it returns the length of the string. If the length of the string minus the frequency of the max frequency character plus the index of the max frequency character is greater than K, it returns the length of the string minus the frequency of the max frequency character plus the index of the max frequency character. Otherwise, it returns the length of the string minus the frequency of the max frequency character.