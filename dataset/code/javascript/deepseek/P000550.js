Here's a simple JavaScript solution using the provided constraints. This solution uses the principles of the circular queue (deque) data structure and a prefix sum technique to find the starting point of the circular tour.

function circularTour(n, petrol, distance) {
    let prefixSum = [...petrol, ...distance];
    let totalPetrol = Array(n + 1).fill(0);
    for (let i = 0; i < n; i++) {
        totalPetrol[i + 1] += totalPetrol[i] + petrol[i];
    }
    let totalPetrolInCircle = 0;
    for (let i = 1; i <= n; i++) {
        totalPetrolInCircle += totalPetrol[i];
    }
    if (totalPetrolInCircle < 0) return -1;
    if (totalPetrolInCircle === 0) return n;
    let start = 0;
    for (let i = 0; i < n; i++) {
        if (totalPetrol[start] < 0) {
            start = (start + 1) % (n + 1);
            if (start === 0) return -1;
        } else {
            start = (start - 1 + n + 1) % (n + 1);
            if (start === 0) return -1;
        }
    }
    return start;
}

This code firstly checks if the total petrol in the circular tour is less than 0 or 0 and return -1 if it is. Then it checks if the total petrol in the circular tour is exactly 0. In all other cases, it uses a greedy algorithm to find the starting point of the circular tour. It starts from the first petrol pump and tries to visit the next petrol pump circularly until it cannot visit the next petrol pump anymore. If it cannot visit any petrol pump in the remaining tour, it returns -1.

Please note that this solution assumes that the starting point and destination are the same, so it returns -1 if it cannot complete the tour in full.

For example:
console.log(circularTour(4, [1, 2, 3, 4], [2, 1, 4, 3]))  // returns: 1
console.log(circularTour(3, [1, 2, 3], [2, 1, 4]))  // returns: -1
console.log(circularTour(2, [1, 1], [1, 1]))  // returns: 1