Here is the JavaScript code for the given problem:

function restoreIpAddresses(s) {
    const results = [];
    const current = [];

    function backtrack(startIndex, segments) {
        if (segments == 4 && startIndex == s.length) {
            results.push(current.slice().join('.'));
            return;
        }

        for (let i = startIndex; i < s.length; i++) {
            const segment = s.slice(startIndex, i + 1);
            if (isNaN(segment)) continue;

            current.push(segment);
            backtrack(i + 1, segments + 1);
            current.pop();

            if (segments == 0 || segments + s.length - i > 3 * (4 - segments)) break;
        }
    }

    backtrack(0, 0);
    return results;
}

console.log(restoreIpAddresses('25525511135'));

This function restores the given pattern into a lexicographically smallest permutation of integers. It uses backtracking to generate all permutations and stores them in the `results` array. The `current` array is used to build up the current permutation, and `startIndex` is used to keep track of the start index of the current segment. The `segments` variable is used to keep track of the number of segments in the current permutation.

Please note that this function assumes that the input string `s` is a valid IP address, and does not validate the input. Also, this function only handles IP addresses up to 4 segments. If you need to handle IP addresses with more than 4 segments, you may need to adjust the backtracking and segment counting parts.