function minOperations(logs) {
    let depth = 0;
    for (const op of logs) {
        if (op === '../') { if (depth > 0) depth--; }
        else if (op !== './') depth++;
    }
    return depth;
}

module.exports = { minOperations };
