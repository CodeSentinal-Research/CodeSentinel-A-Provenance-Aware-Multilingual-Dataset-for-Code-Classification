/**
 * Converts a temperature from Celsius to Fahrenheit.
 * @param {number|string} celsius - The temperature in Celsius.
 * @returns {number} The temperature in Fahrenheit.
 * @throws {TypeError} If the input is not a valid number.
 */
function celsiusToFahrenheit(celsius) {
  const temperature = Number(celsius);
  if (Number.isNaN(temperature) || !Number.isFinite(temperature)) {
    throw new TypeError('Invalid temperature value');
  }
  return temperature * 9 / 5 + 32;
}