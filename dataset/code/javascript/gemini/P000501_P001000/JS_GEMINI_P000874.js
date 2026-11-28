// Helper function to evaluate decode for problem constraints.
function decode(encoded) {
    const n = encoded.length + 1;
    let totalXor = 0;
    for (let i = 1; i <= n; i++) totalXor ^= i;
    let oddXor = 0;
    for (let i = 1; i < encoded.length; i += 2) oddXor ^= encoded[i];
    const perm = [totalXor ^ oddXor];
    for (let i = 0; i < encoded.length; i++) {
        perm.push(perm[i] ^ encoded[i]);
    }
    return perm;
}

module.exports = { decode };