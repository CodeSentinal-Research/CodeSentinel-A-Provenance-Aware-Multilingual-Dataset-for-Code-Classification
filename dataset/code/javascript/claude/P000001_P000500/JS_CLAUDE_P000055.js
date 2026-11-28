function printAlphabetZA() {
    let res = "";
    for (let i = 90; i >= 65; i--) {
        res += String.fromCharCode(i);
    }
    return res;
}

module.exports = { printAlphabetZA };
