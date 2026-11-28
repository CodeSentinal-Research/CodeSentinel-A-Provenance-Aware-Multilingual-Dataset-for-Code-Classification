function midpoint(x1, y1, x2, y2) {
    if (!Number.isInteger(x1) || !Number.isInteger(y1) || !Number.isInteger(x2) || !Number.isInteger(y2)) {
        throw new Error('All inputs must be integers.');
    }
    if (x1 === x2) {
        throw new Error('The endpoints must be different.');
    }
    if (x1 > x2) [x1, x2] = [x2, x1];
    if (y1 > y2) [y1, y2] = [y2, y1];
    var midX = Math.round((x1 + x2) / 2);
    var midY = Math.round((y1 + y2) / 2);
    return {x: midX, y: midY};
}