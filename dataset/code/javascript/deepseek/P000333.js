Here is the JavaScript code that solves the problem:

function numMatchingSubsequences(S, words) {
    let count = 0;
    const wordSet = new Set(words);
    for (const word of wordSet) {
        if (isSubsequence(S, word)) {
            count++;
        }
    }
    return count;
}

function isSubsequence(s, t) {
    let i = 0, j = 0;
    while (i < s.length && j < t.length) {
        if (s[i] === t[j]) {
            i++;
        }
        j++;
    }
    return i === s.length;
}

In the above code, the `numMatchingSubsequences` function first constructs a set of unique words from the input list. Then for each word in the set, it calls the `isSubsequence` function to check if the word is a subsequence of the given string. If it is, the count is incremented. Finally, the count is returned as the result.

The `isSubsequence` function checks if a word is a subsequence of another word. It uses a two-pointer approach. The first pointer (i) iterates over the string S and the second pointer (j) iterates over the string T. If the character at the current pointer of each is the same in both strings, it means they are in the same position, so it increments the pointer of the first one. If not, it just increments the pointer of the second one.
After all characters in the string S have been compared with the corresponding characters in string T, if the pointer of the first one reaches the end of S (i === s.length), then it means S is a subsequence of T and it returns true. Otherwise, it returns false.