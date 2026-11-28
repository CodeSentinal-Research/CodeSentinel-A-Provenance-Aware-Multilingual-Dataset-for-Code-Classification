// Helper function to evaluate decode for problem constraints.
function decode(encoded, first) {
    const res = [first];
    for (let i = 0; i < encoded.length; i++) {
        res.push(res[i] ^ encoded[i]);
    }
    return res;
}

module.exports = { decode };