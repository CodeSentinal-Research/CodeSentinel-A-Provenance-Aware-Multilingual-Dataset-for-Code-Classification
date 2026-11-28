function calculateDistance(x1, y1, x2, y2) {
  if (
    typeof x1 === 'number' &&
    typeof y1 === 'number' &&
    typeof x2 === 'number' &&
    typeof y2 === 'number'
  ) {
    let distance = Math.sqrt(Math.pow((x2 - x1), 2) + Math.pow((y2 - y1), 2))
    return distance
  } else {
    throw new Error("All input values must be numbers.")
  }
}
This code defines a function `calculateDistance` that takes four arguments: `x1`, `y1`, `x2`, and `y2`. It first checks if all inputs are numbers. If they are, it calculates the distance using the Pythagorean theorem and returns the result. If there's any problem (i.e., if any of the inputs is not a number), it throws an error.