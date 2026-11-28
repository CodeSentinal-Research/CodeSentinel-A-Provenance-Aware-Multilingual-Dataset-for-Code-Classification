Here is a JavaScript solution for the problem:

function computeAreaOfTriangle(coordinates) {
    // Extract the coordinates
    const [x1, y1, x2, y2, x3, y3] = coordinates;

    // Calculate the area
    const area = Math.abs((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2);

    return area;
}

// Input handling
const inputCoordinates = process.argv[2];
try {
    if (!inputCoordinates) throw new Error('Input is missing.');
    const coordinates = inputCoordinates.split(',').map(Number);
    if (coordinates.length !== 6) throw new Error('Invalid input.');
    const area = computeAreaOfTriangle(coordinates);
    console.log(`Area of the triangle is: ${area}`);
} catch (error) {
    console.error(`Invalid input: ${inputCoordinates}`);
}

This program takes the coordinates as command-line arguments. It checks if the input is valid (i.e., it is a string of comma-separated numbers), and if it is, it splits the string into an array of numbers, and passes it to the `computeAreaOfTriangle` function to calculate the area. If the input is not valid, it logs an error message to the console.

You can run this program in Node.js by passing the coordinates as command-line arguments. For example, `node script.js 0,0 0,6 2,6` would compute the area of a triangle with vertices at the coordinates (0,0), (0,6), and (2,6).