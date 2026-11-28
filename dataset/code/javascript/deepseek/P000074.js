Here's the JavaScript code:

function calculateSphereVolume(radius) {
  var pi = 3.14159;
  var volume = (4/3) * pi * Math.pow(radius, 3);
  return volume;
}

// usage
var radius = prompt("Enter the radius of the sphere (0 to 50): ");

if (radius >= 0 && radius <= 50) {
  var volume = calculateSphereVolume(radius);
  console.log("The volume of the sphere is " + volume);
} else {
  console.log("Invalid input, please enter a number between 0 and 50.");
}

In this code, the user is asked to enter the radius of the sphere. If the input is not within the specified range (0 to 50), an error message is displayed. If the input is valid, the volume of the sphere is calculated and displayed.