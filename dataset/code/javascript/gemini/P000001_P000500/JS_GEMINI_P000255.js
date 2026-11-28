function removeVowels(s) {
    return s.replace(/[aeiouAEIOU]/g, '');
}

module.exports = { removeVowels };