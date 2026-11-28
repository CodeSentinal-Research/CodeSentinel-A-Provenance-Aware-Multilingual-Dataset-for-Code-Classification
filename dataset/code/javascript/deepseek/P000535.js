Here is the JavaScript code for the problem:

function deckRevealedIncreasing(deck) {
  const n = deck.length;
  const deckRevealed = new Array(n).fill(null);
  const deckRevealedIndex = new Array(n).fill(0);
  let topCard = 0;
  let bottomCard = 1;

  for (let i = 0; i < n; i++) {
    deckRevealed[bottomCard] = deck[i];
    const tmp = bottomCard;
    bottomCard = topCard + 1;
    topCard = tmp;
    deckRevealedIndex[bottomCard] = i;
  }

  return deckRevealed;
}

console.log(deckRevealedIncreasing([1, 2, 3, 4, 5]));

This script creates a new array `deckRevealed` to represent the final order of the deck. It maintains an `index` array to track the order of the cards in the `deck`.

In each round of the game, it first reveals the top card and places it at the bottom of the `deckRevealed` array. Then it moves the next top card to the bottom. This is done by updating the `bottomCard` to be the current `topCard` and `topCard` to be the next card in the `deck`.

The `deckRevealedIndex` array is used to map the index in the `deck` to the index in the `deckRevealed`.

The time complexity of this algorithm is O(n) as it only requires a single pass through the `deck`.