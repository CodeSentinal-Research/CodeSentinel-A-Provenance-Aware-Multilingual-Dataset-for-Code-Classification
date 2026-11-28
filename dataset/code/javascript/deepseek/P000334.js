Here is the JavaScript code for finding the minimum number of subsequences needed to form the target from the source:

function minSubsequence(source, target) {
    if (source.length > target.length) {
        return -1;
    }
    let count = 0;
    for (let i = 0; i < source.length; i++) {
        count += target.includes(source[i]);
    }
    return count === target.length ? source.length : -1;
}

This function iterates through the source and checks if each character in the source is in the target string. If it is, it increases a counter. At the end, it returns the length of the target if the counter is equal to its length, otherwise it returns -1. This function assumes that the source string is a subsequence of the target string, and that the source string contains no duplicates.