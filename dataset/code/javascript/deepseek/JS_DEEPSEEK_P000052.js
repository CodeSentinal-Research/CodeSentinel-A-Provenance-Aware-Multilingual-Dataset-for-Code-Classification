/**
 * Converts an uppercase character to its lowercase equivalent.
 * Safely handles null, undefined, and non-string inputs.
 * @param {*} char - The character to convert.
 * @returns {string} The lowercase equivalent, or empty string for null/undefined.
 */
const toLowerCase = (char) => {
  if (char == null) return '';
  const s = String(char);
  return s.length ? s.toLowerCase() : s;
};