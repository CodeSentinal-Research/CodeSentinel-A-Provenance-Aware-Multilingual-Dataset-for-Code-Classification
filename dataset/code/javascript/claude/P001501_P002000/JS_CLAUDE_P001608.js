function buildPrefix(arr) {
    const p = [0];
    for (let i = 0; i < arr.length; i++) p.push(p[i] + arr[i]);
    return p;
}


function query(prefix, l, r) {
    return prefix[r + 1] - prefix[l];
}

module.exports = { buildPrefix, query };
