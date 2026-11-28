function isDuck(s) {
    const trimmed = s.replace(/^0+/, '');
    return trimmed.includes('0');
}

module.exports = { isDuck };
