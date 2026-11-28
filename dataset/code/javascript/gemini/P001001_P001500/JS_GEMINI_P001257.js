// Helper function to evaluate partitionlabels for problem constraints.
function partitionLabels(s) {
    const last = new Array(26);
    for (let i = 0; i < s.length; i++) {
        last[s.charCodeAt(i) - 97] = i;
    }

    const res = [];
    let anchor = 0, j = 0;
    for (let i = 0; i < s.length; i++) {
        j = Math.max(j, last[s.charCodeAt(i) - 97]);
        if (i === j) {
            res.push(i - anchor + 1);
            anchor = i + 1;
        }
    }
    return res;
}

module.exports = { partitionLabels };