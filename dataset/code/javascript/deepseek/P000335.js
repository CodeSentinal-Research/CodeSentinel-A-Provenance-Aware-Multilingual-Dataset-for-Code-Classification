Here is the JavaScript code for the problem:

function camelcaseMatchingQueries(queries, pattern) {
  const match = (q, p) => {
    let j = 0;
    for (let i = 0; i < q.length; i++) {
      if (q[i] === p[j]) j++;
      if (j === p.length) return true;
    }
    return false;
  }
  
  return queries.map(q => match(q, pattern));
}

In this code, we create a helper function `match` that iterates through the query and the pattern. For each query character, if the character in the query matches the next character in the pattern, we increment the index for the pattern. If we've matched the entire pattern in the query, we return true. If we've matched all characters in the pattern in the query, we return false.

Then, we use the `map` function to apply this `match` function to each query in the list of queries. The `map` function returns a new array with the results of calling the provided function on every element in the original array.

The time complexity of this solution is O(n*m), where n is the number of queries and m is the length of the pattern. This is because for each query, we iterate through each character in the query and each character in the pattern. The space complexity is O(n*m) as well, due to the additional space needed for the results array.