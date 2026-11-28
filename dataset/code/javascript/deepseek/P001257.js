Here is a JavaScript code to solve the problem:

function partitionLabels(S) {
    let last = new Array(26).fill(-1);
    for (let i = S.length - 1; i >= 0; i--) {
        last[S.charCodeAt(i) - 'a'.charCodeAt(0)] = i;
    }

    let anchor = -1;
    let result = [];

    for (let i = 0; i < S.length; i++) {
        anchor = Math.max(anchor, last[S.charCodeAt(i) - 'a'.charCodeAt(0)]);
        if (i === anchor) {
            result.push(i - anchor);
            anchor++;
        }
    }

    return result;
}

This code uses an array `last` to store the last index of each character in the string. Then, it iterates over the string from left to right. For each character, it sets the anchor to be the maximum of the anchor and the last index of the current character. If the current index is equal to the anchor, it means that all characters before the current index have been processed, so it adds the length of the partition to the result and increases the anchor by one.