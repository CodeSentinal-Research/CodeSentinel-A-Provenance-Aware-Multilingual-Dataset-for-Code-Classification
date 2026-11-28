Sure, here is the JavaScript code for the problem:

function convertTime(seconds) {
  if (seconds < 0 || seconds > 86400) {
    return "Invalid input. Please enter a non-negative integer between 0 and 86400.";
  }
  
  var hours = Math.floor(seconds / 3600);
  var minutes = Math.floor((seconds % 3600) / 60);
  var remainingSeconds = seconds % 60;

  return `Hours: ${hours}, Minutes: ${minutes}, Seconds: ${remainingSeconds}`;
}
This function takes a non-negative integer `seconds` as an input and returns a string with the time in hours, minutes, and seconds. It first checks if the input is valid (between 0 and 86400), and if not, returns an error message. Otherwise, it calculates the number of hours, minutes, and remaining seconds using integer division and modulus operations, and returns the result as a string.