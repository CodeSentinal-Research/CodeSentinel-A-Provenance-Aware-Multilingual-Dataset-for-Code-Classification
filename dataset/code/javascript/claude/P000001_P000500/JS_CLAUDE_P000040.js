function getAllAscii() {
    const list = [];
    for (let i = 0; i < 128; i++) {
        list.push([i, String.fromCharCode(i)]);
    }
    return list;
}

module.exports = { getAllAscii };
