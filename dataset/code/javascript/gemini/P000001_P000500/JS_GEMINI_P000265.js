function removeDuplicates(s) {
    return Array.from(new Set(s)).join('');
}

module.exports = { removeDuplicates };