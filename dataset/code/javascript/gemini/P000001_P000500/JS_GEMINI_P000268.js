function countWords(s) {
    const words = s.trim().split(/\s+/);
    return words[0] === '' ? 0 : words.length;
}

module.exports = { countWords };