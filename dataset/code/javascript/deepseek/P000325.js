Here is the JavaScript code that solves the problem:

function longestUncommonSubseq(A, B) {
    if (A === B) {
        return -1;
    }
    return Math.max(A.length, B.length);
}

In this code, we are checking if the two strings are the same and if they are not, we are returning the maximum length of the two strings. The `Math.max` function is used to determine the maximum length between the lengths of the two strings.