function solve() {
  let n = parseInt(readline());
  let tree = new Array(n + 1).fill(null).map((_, i) => i);
  let parent = new Array(n + 1).fill(null);
  for (let i = 1; i <= n; i++) {
    let [node, left, right] = readline().split(' ').map(Number);
    if (left != -1) {
      tree[node] = left;
      parent[left] = node;
    }
    if (right != -1) {
      tree[node] = right;
      parent[right] = node;
    }
  }

  function dfs(node) {
    if (!node) return 0;
    return dfs(tree[node]) + node;
  }

  let sums = new Array(n + 1).fill(0).map((_, i) => dfs(i));
  let maxLevel = sums.indexOf(Math.max(...sums));
  let maxSum = sums[maxLevel];

  let minLevel = [];
  let maxSumLevel = maxSum;
  while (maxSumLevel != 0) {
    minLevel.push(maxSumLevel);
    maxSumLevel = parent[maxSumLevel];
  }

  console.log(minLevel[minLevel.length - 1]);
}

function readline() {
  return process.env.NODE_ENV === 'development' ? require('fs').readFileSync('/dev/stdin', 'utf8') : process.stdin.readline();
}

solve();