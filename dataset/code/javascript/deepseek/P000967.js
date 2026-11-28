function earliestTimestamp(n) {
    // Initialize earliestTimestamp to Infinity
    let earliestTimestamp = Infinity;

    // Initialize congruences array
    const congruences = [];

    // Ask for inputs from user
    for(let i = 0; i < n; i++) {
        let congruence = prompt('Enter congruence ' + (i + 1) + ':');
        congruences.push(congruence);
    }

    // Loop through congruences
    for(let i = 0; i < n; i++) {
        // Pull out congruence
        const congruence = congruences[i];

        // Split congruence into two parts by ' '
        const [a, op, b, c] = congruence.split(' ');

        // Map operator to operator object
        const operator = op === '<' ? -1 : op === '>' ? 1 : 0;

        // Check if timestamp is valid and is less than earliestTimestamp
        if(a < b || (a === b && (c - b) * operator < earliestTimestamp)) {
            earliestTimestamp = (c - b) * operator;
        }
    }

    // If earliestTimestamp is still Infinity, return 0
    if(earliestTimestamp === Infinity) {
        return 0;
    }

    // Return earliestTimestamp
    return earliestTimestamp;
}