Here is the JavaScript code:

function calculateVolume(length, breadth, height) {
    if (length > 0 && length <= 100 && breadth > 0 && breadth <= 100 && height > 0 && height <= 100) {
        return length * breadth * height;
    } else {
        throw new Error("Input values should be between 1 and 100");
    }
}

// Test the function
console.log(calculateVolume(5, 6, 7));  // Should print 360

In the function calculateVolume, we first check if the input values are within the range of 1 to 100. If they are, we calculate the volume of the cuboid and return it. If they are not, we throw an error. The test of the function is done in the last line.