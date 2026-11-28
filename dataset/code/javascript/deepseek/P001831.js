function countTrees(n) {
  if (n <= 1) return 1;

  let count = 0;
  for (let i = 0; i < n; i++) {
    let leftTrees = countTrees(i);
    let rightTrees = countTrees(n - i - 1);
    count += leftTrees * rightTrees;
  }

  return count;
}

function main() {
  const n = process.argv[2] || 0;
  if (n < 0 || n > 1000) {
    console.log("Invalid input. Please provide a number between 0 and 1000");
    return;
  }
  
  console.log(countTrees(n));
}

main();
In the above code, we use recursion to calculate the number of unique BSTs for each possible prefix of keys, starting from the first one. This way we can build each tree from the prefix of keys. The recursion is called till the end of keys, when the recursion is finished, we have all possible unique trees for the given prefix.