function isSpecial(c) {
    return !/[a-zA-Z0-9\s]/.test(c);
}

module.exports = { isSpecial };
