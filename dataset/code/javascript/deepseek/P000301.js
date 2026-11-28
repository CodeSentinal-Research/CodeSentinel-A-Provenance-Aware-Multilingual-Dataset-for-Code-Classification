Here's the JavaScript code that restores all possible valid IP addresses from a string of digits:

function restoreIpAddresses(s) {
    const output = [];
    const current = [];
    backtrack(s, 0, 0, current, output);
    return output;
}

function backtrack(s, startIndex, segmentCount, current, output) {
    if (segmentCount > 4) {
        return;
    }
    if (segmentCount === 4 && startIndex === s.length) {
        output.push(current.join('.'));
        return;
    }
    for (let i = startIndex; i < s.length; i++) {
        const segment = s.slice(startIndex, i + 1);
        if (segment.length > 1 && segment.startsWith('0')) {
            break;
        }
        if (segment >= 0 && segment <= 255) {
            current.push(segment);
            backtrack(s, i + 1, segmentCount + 1, current, output);
            current.pop();
        } else {
            break;
        }
    }
}
This solution uses backtracking to generate all possible IP addresses from the given string. It iterates over each character in the string, and for each character, it tries to make a segment of length from the startIndex to the current index. If the segment is valid (i.e., it's a number between 0 and 255), it adds the segment to the current list and recurses with the next index. If the segment is not valid, it breaks out of the loop.