Here's the JavaScript code for the problem:

function findCelebrity(matrix) {
    const N = matrix.length;

    // Initialize two arrays: one for celebrity's knows and the other for celebrity's doesn't know
    const knows = new Array(N).fill(0).map(() => new Array(N).fill(false));
    const doesNotKnow = new Array(N).fill(0).map(() => new Array(N).fill(false));

    // Fill the arrays
    for (let i = 0; i < N; i++) {
        for (let j = 0; j < N; j++) {
            if (matrix[i][j] === 1) {
                knows[i][j] = true;
                doesNotKnow[j][i] = true;
            }
        }
    }

    // For each person, check if they are a celebrity by comparing them to all other people
    // This means that they don't know anyone and everyone knows them
    for (let i = 0; i < N; i++) {
        let isCelebrity = true;
        for (let j = 0; j < N; j++) {
            // Person i doesn't know person j
            if (!knows[i][j] && doesNotKnow[j][i]) {
                isCelebrity = false;
                break;
            }
        }

        // If person i is a celebrity, return it
        if (isCelebrity) {
            return i;
        }
    }

    // If no celebrity is found, return -1
    return -1;
}
This code first creates two arrays to keep track of who knows whom. It then fills these arrays based on the input matrix. Then it iterates through each person and checks if they are a celebrity by comparing them to all other people. If they don't know anyone and everyone knows them, they are a celebrity. If no celebrity is found, it returns -1.