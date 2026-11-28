Here is the JavaScript code:

function calculateVolumeOfCube(side) {
  if (side < 1 || side > 100) {
    throw new Error("Invalid input. Side length must be between 1 and 100");
  }

  var volume = Math.pow(side, 3);

  return volume;
}
This function takes one argument: the side length of the cube. It first checks if the side length is between 1 and 100, if not, it throws an error. Then it calculates the volume by cubing the side length and returns the result.