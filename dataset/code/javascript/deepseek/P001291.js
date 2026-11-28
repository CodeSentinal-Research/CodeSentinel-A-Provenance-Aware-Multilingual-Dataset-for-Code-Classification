function canFormHand(n, k, cards) {
  // Check if the input is valid
  if (n < 1 || n > 2 * 10 ^ 5 || k < 1 || k > n || !Array.isArray(cards) || cards.length !== n) {
    throw new Error('Invalid input');
  }

  // Count the frequency of each card
  const count = {};
  for (let card of cards) {
    count[card] = (count[card] || 0) + 1;
  }

  // Check if it's possible to form a hand of K consecutive cards
  for (let i = 0; i < n; i++) {
    if (count[cards[i]] > 0) {
      count[cards[i]]--;
      if (count[cards[i]] == 0) {
        delete count[cards[i]];
      }
      if (Object.keys(count).length == i + k - 1) {
        return 'YES';
      }
    } else if (i >= k - 1) {
      for (let j = 1; j <= k; j++) {
        if (!count[cards[i - j]]) {
          return 'NO';
        }
      }
    }
  }
  return 'NO';
}
This JavaScript code defines a function `canFormHand` that checks if it's possible to rearrange the given cards into groups of K consecutive cards. The function first validates the input. Then it counts the frequency of each card and checks if it's possible to form a hand of K consecutive cards.