let fs = require('fs');
let input = fs.readFileSync('input.txt', 'utf8');
input = input.split('\n');
let N = Number(input[0].split(' ')[0]);
let K = Number(input[0].split(' ')[1]);
let A = input[1].split(' ').map(Number);

function jumpGameVI(A, K) {
    let score = 0;
    let maxScore = 0;
    let jumps = [];
    
    for (let i = 0; i < A.length; i++) {
        let pos = A[i];
        let maxJump = Math.min(pos, pos + K);
        let maxJumpIndex = A.slice(0, maxJump - pos + 1).indexOf(Math.max(...A.slice(0, maxJump - pos + 1)));
        score += A[maxJumpIndex];
        maxScore = Math.max(maxScore, score);
   
        jumps.push(maxJumpIndex);
        
        if (i % 2 === 0 && i !== A.length - 1) {
            let nextPos = A[i + 1];
            if (nextPos > pos + K) {
                let nextMaxJump = Math.min(nextPos, pos + K);
                let nextMaxJumpIndex = A.slice(nextMaxJump - pos + 1).indexOf(Math.max(...A.slice(nextMaxJump - pos + 1)));
                score += A[nextMaxJumpIndex];
                maxScore = Math.max(maxScore, score);
            }
        }
    }

    return maxScore;
}

console.log(jumpGameVI(A, K));