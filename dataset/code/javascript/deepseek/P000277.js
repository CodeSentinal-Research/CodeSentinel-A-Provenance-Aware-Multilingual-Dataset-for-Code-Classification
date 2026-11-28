Here is the JavaScript code for finding the length of the longest substring without repeating characters:

function lengthOfLongestSubstring(s) {
    let map = new Map();
    let start = 0;
    let maxLen = 0;

    for(let i = 0; i < s.length; i++){
        if(map.has(s[i])){
            start = Math.max(start, map.get(s[i]) + 1);
        }
        map.set(s[i], i);
        maxLen = Math.max(maxLen, i - start + 1);
    }

    return maxLen;
}

In this code, we use a Map to store the last seen index of each character. If we find a character we have seen before, we update the start point to be the index of the last seen character plus one because the current character could be part of the longest substring ending at the last seen character. We also update the maximum length substring found so far.