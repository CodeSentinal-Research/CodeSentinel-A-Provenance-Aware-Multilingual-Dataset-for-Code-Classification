function checkVowelOrConsonant(c) {
    if (!/[a-zA-Z]/.test(c)) return "Neither";
    return /[aeiouAEIOU]/.test(c) ? "Vowel" : "Consonant";
}

module.exports = { checkVowelOrConsonant };
