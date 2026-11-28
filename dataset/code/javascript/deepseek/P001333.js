function addOperators(num, target) {
  let res = [];
  dfs(num, target, 0, 0, '', 0, 0, true);
  return res;

  function dfs(num, target, idx, last, path, exp, sum) {
      if (idx === num.length) {
          if (sum === target) {
              res.push(path);
          }
          return;
      }
      let cur = 0;
      sum += last;
      for (let i = idx; i < num.length; ++i) {
          cur = cur * 10 + num[i] - '0';
          if (idx === 0) {
              dfs(num, target, i + 1, cur, cur + '', cur, cur);
          } else {
              dfs(num, target, i + 1, cur, path + '+' + cur, sum + cur, cur);
              dfs(num, target, i + 1, -cur, path + '-' + cur, sum - cur, -cur);
              dfs(num, target, i + 1, last * cur, path + '*' + cur, sum - last + last * cur, last * cur);
          }
          if (num[idx] === '0') break;
      }
  }
}

This JavaScript function uses a depth-first search (DFS) approach to find all the expressions that can be formed by inserting the operators between the digits in the given number. The dfs function accepts four arguments: the number, the target, the index of the current character in the number, the last number in the expression, the current expression, the sum of the expression, and a boolean to indicate if the previous character was '0'. The function iterates over the digits in the number and performs the DFS recursion for each digit. If the current character is '0', it breaks the loop as it cannot be the first character in the expression.