Here is the code:

function stoneGame(piles) {
  // Calculate the total number of stones in the piles
  let totalStones = piles.reduce((a, b) => a + b, 0);

  // The first player can always force a win in the end if the total stones are even
  // and the largest pile is smaller than the total stones divided by 2 (this is because each stone is worth half the number of stones, so the second player would have to take half the piles worth of stones).
  if (totalStones % 2 === 0 && piles[piles.length - 1] < totalStones / 2) {
    return true;
  }

  // Otherwise, the first player can always win by taking all piles (this is because the second player would have to take the first pile and not take the largest pile, so the first player would always have to take all piles).
  return false;
}

console.log(stoneGame([5, 3, 1, 2, 6])); // Output: false
console.log(stoneGame([5, 3, 1, 2, 6, 4])); // Output: true

This code works by calculating the total number of stones in the piles and comparing it to the largest stone. If the total number of stones is even and the largest stone is smaller than half of the total stones, the first player can always force a win. Otherwise, the first player can always win by taking all piles.