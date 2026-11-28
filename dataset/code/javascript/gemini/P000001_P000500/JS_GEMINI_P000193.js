function doUnion(arr1, arr2) {
    const set = new Set([...arr1, ...arr2]);
    return set.size;
}

module.exports = { doUnion };