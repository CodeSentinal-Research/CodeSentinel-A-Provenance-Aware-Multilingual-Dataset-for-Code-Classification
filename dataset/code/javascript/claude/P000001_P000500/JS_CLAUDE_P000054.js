function printAlphabetAZ() {
    let res = "";
    for (let i = 65; i <= 90; i++) {
        res += String.fromCharCode(i);
    }
    return res;
}

module.exports = { printAlphabetAZ };
