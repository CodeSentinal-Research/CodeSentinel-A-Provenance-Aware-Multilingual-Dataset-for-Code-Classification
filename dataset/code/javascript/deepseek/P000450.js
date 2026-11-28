function findKthMissingPositive(n, arr) {
  // Initialize a set to store unique positive numbers
  const uniqueNums = new Set(arr);

  // Generate all unique positive numbers
  for (let i = 1; i <= n * 2; i++) {
    if (!uniqueNums.has(i)) {
      uniqueNums.add(i);
    }
  }

  // Convert the set to array and sort
  const sortedUniqueNums = Array.from(uniqueNums).sort((a, b) => a - b);

  // Check if k is larger than the length of sorted array
  if (sortedUniqueNums.length < k) {
    throw new Error('k is larger than the length of sorted array');
  }

  // Return the kth element
  return sortedUniqueNums[k - 1];
}