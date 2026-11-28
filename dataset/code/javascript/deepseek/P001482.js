process.stdin.resume();
process.stdin.on('data', function(data) {
    var input = data.toString().trim().split('\n');
    var N = parseInt(input[0]);
    var tokens = input[1].split(' ').map(Number);
    var power = parseInt(input[2]);
    console.log(maxScore(N, tokens, power));
});

function maxScore(N, tokens, power) {
    tokens.sort((a, b) => b - a);
    var score = 0;
    while (power > 0 && tokens.length > 0) {
        if (power >= tokens[0]) {
            power -= tokens.shift();
            score += 1;
        } else if (tokens.length > 1) {
            power += tokens.pop();
            score -= 1;
        } else {
            tokens.shift();
        }
    }
    return score;
}