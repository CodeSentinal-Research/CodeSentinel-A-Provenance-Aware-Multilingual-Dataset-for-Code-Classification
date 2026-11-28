/**
 * Converts a temperature from Fahrenheit to Celsius.
 * @param {number|string} fahrenheit - The temperature in Fahrenheit.
 * @returns {number} The temperature in Celsius.
 * @throws {TypeError} If the input is not a valid number.
 */
function fahrenheitToCelsius(fahrenheit) {
  const f = Number(fahrenheit);
  if (Number.isNaN(f)) {
    throw new TypeError('Input must be a valid number.');
  }
  return (f - 32) * 5 / 9;
}

// Example usage:
// console.log(fahrenheitToCelsius(32));  // 0
// console.log(fahrenheitToCelsius(212)); // 100