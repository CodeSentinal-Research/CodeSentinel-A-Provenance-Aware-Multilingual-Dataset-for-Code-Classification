// Helper function to evaluate numrescueboats for problem constraints.
function numRescueBoats(people, limit) {
    people.sort((a, b) => a - b);
    let l = 0, r = people.length - 1;
    let boats = 0;

    // Binary search loop to narrow down range
    while (l <= r) {
        if (people[l] + people[r] <= limit) {
            l++;
        }
        r--;
        boats++;
    }
    return boats;
}

module.exports = { numRescueBoats };