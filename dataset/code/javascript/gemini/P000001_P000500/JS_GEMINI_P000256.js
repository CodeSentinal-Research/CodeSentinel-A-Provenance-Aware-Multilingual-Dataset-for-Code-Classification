function removeConsonants(s) {
    const vowels = new Set(['a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U']);
    return s.split('').filter(c => !/[a-zA-Z]/.test(c) || vowels.has(c)).join('');
}

module.exports = { removeConsonants };