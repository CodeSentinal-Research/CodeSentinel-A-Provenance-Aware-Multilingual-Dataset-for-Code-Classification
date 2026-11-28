function isDuckNumber(s) {
    const str = String(s).trim();
    if (!str || str[0] === '0') return false;
    return str.includes('0');
}

module.exports = { isDuckNumber };