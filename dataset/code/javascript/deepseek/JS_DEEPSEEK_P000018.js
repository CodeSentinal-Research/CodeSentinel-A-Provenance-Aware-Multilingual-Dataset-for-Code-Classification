/**
 * Checks if a given year is a leap year.
 * @param {number} year - The year to evaluate.
 * @returns {boolean} - True if the year is a leap year, false otherwise.
 * @throws {TypeError} If the year is not a valid integer.
 */
function isLeapYear(year) {
  if (typeof year !== 'number' || !Number.isInteger(year) || !Number.isFinite(year)) {
    throw new TypeError('Year must be a valid integer.');
  }
  return (year % 4 === 0 && year % 100 !== 0) || year % 400 === 0;
}

module.exports = { isLeapYear };