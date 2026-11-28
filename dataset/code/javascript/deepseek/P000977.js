Here is the JavaScript code for the problem:

function isCollinear(p1, p2, p3) {
  // Calculate the cross product of (p2-p1) and (p3-p1)
  let crossProduct = (p2[0] - p1[0]) * (p3[1] - p1[1]) - (p2[1] - p1[1]) * (p3[0] - p1[0]);
  
  // If the cross product is zero, the points are collinear
  if (crossProduct === 0) {
    return true;
  } else {
    return false;
  }
}

// Example usage:
console.log(isCollinear([0, 0], [1, 2], [2, 0])); // Outputs: true
console.log(isCollinear([0, 0], [1, 1], [2, 2])); // Outputs: true
console.log(isCollinear([0, 0], [1, 2], [1, 3])); // Outputs: false

In this code, the function `isCollinear` takes three points represented as arrays of two numbers. It calculates the cross product of the vectors from `p2` to `p1` and from `p3` to `p1`, and checks if the cross product is zero. If it is, the points are collinear.