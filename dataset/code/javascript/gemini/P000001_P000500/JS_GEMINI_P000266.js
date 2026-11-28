function removeOccurrences(s, c) {
    return s.split(c).join('');
}

module.exports = { removeOccurrences };