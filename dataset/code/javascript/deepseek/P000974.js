Sure, here is the JavaScript code for finding the Euclidean distance between two points:

function euclideanDistance(x1, y1, x2, y2) {
    if (typeof x1 !== 'number' || typeof y1 !== 'number' || typeof x2 !== 'number' || typeof y2 !== 'number') {
        throw new Error('All coordinates must be numbers.');
    }
    if (!Number.isInteger(x1) || !Number.isInteger(y1) || !Number.isInteger(x2) || !Number.isInteger(y2)) {
        throw new Error('All coordinates must be integers.');
    }
    if (Math.abs(x1) > 10^9 || Math.abs(y1) > 10^9 || Math.abs(x2) > 10^9 || Math.abs(y2) > 10^9) {
        throw new Error('Coordinates must be within the range (-10^9, 10^9).');
    }
    return Math.sqrt(Math.pow(x2 - x1, 2) + Math.pow(y2 - y1, 2));
}

This function takes four arguments: the x and y coordinates of the two points. It first checks if all arguments are numbers and if they are integers. It then checks if the coordinates are within the range (-10^9, 10^9). Finally, it calculates and returns the Euclidean distance between the two points.