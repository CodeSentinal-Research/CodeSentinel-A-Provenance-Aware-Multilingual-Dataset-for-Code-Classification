function isSpecialSymbol(char) {
  if (typeof char !== 'string' || char.length !== 1) {
    return false;
  }

  // Returns true if the character is not alphanumeric and not whitespace
  return /[^a-zA-Z0-9\s]/.test(char);
}

module.exports = isSpecialSymbol;