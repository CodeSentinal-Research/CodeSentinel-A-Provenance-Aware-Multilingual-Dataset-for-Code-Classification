Here is the JavaScript code for the given problem:

function findFirstPlayerWin(piles) {
    let totalStones = piles.reduce((a, b) => a + b, 0);
    let firstPlayerStones = piles[0];
    for (let i = 1; i < piles.length; i++) {
        if (piles[i] !== 0) {
            if (firstPlayerStones % piles[i] === 0) {
                firstPlayerStones += piles[i];
            } else {
                firstPlayerStones += piles[i] % firstPlayerStones;
           
            }
        }
    }

    return firstPlayerStones % 2 === 0 ? "Second" : "First";
}

// Test the function
console.log(findFirstPlayerWin([5, 10, 10, 100, 10]));

This code computes the total number of stones and the first player's initial number of stones. It then iterates over the piles, and for each pile, if the current pile's stones are divisible by the previous pile's stones, it adds the current pile's stones to the first player's stones. Otherwise, it adds the remainder of the current pile's stones divided by the first player's stones to the first player's stones. After each turn, it checks whether the first player has a winning strategy.