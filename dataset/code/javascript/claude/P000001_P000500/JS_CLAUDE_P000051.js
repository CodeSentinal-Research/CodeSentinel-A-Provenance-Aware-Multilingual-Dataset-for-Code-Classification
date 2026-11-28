function checkCase(c) {
    if (/[A-Z]/.test(c)) return "Uppercase";
    if (/[a-z]/.test(c)) return "Lowercase";
    return "Not an alphabet";
}

module.exports = { checkCase };
