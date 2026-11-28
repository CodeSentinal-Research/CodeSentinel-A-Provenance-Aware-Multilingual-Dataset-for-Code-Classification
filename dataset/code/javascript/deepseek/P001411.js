Here is the JavaScript code for the problem.

function findPlayers(matches) {
  const map = new Map();
  for (let match of matches) {
    let winner = match[0];
    let loser = match[1];

    if (map.has(winner)) {
      map.set(winner, map.get(winner) + 1);
    } else {
      map.set(winner, 1);
    }

    if (map.has(loser)) {
      map.set(loser, map.get(loser) - 1);
    } else {
      map.set(loser, -1);
    }
  }

  let playersWithZeroLosses = [];
  let playersWithOneLoss = [];
  for (let [player, lossCount] of map) {
    if (lossCount === 0) {
      playersWithZeroLosses.push(player);
    } else if (lossCount === 1) {
      playersWithOneLoss.push(player);
    }
  }

  playersWithZeroLosses.sort((a, b) => a - b);
  playersWithOneLoss.sort((a, b) => a - b);

  console.log(`Players with zero losses: ${playersWithZeroLosses.join(', ')}`);
  console.log(`Players with exactly one loss: ${playersWithOneLoss.join(', ')}`);
}

In this code, we use a Map to store the number of losses for each player. The Map's keys are players and the values are the loss counts. We iterate over the matches, updating the loss counts for each player. When a player loses, we increment their loss count; when they win, we decrement the loss count. After all matches have been processed, we then iterate over the Map to find players who lose exactly once and who lose zero times.

This solution assumes that the input is passed in as an array of arrays, where each inner array contains two integers representing the winner and loser. It is assumed that the input will be in a valid format for this problem, as per the constraints.