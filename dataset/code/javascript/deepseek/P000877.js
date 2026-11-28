function minBitFlips(start, goal) {
    // Convert both numbers to binary and remove the '0b' at the start of the string
    start = start.toString(2).slice(2);
    goal = goal.toString(2).slice(2);

    // If the lengths are not equal, pad with zeros on the left to make them equal
    if (start.length < goal.length) {
        start = start.padStart(goal.length, '0');
    } else if (goal.length < start.length) {
        goal = goal.padStart(start.length, '0');
    }

    // Convert the strings back to numbers
    start = parseInt(start, 2);
    goal = parseInt(goal, 2);

    // Calculate the absolute difference
    let diff = Math.abs(start - goal);

    // Count the number of flips needed (half of a bit is needed to flip a bit)
    return Math.floor(diff / 2);
}