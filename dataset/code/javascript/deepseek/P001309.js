function survivalOnIsland() {
  let [S, N, M] = readline().split(' ').map(Number);
  if (S + N + M < 3) {
    console.log(-1);
  } else {
    let days = [S, N, M];
    days.sort((a, b) => b - a);
    let i = 0;
    while (S < days[i] && days[i + 1] <= S + M) {
      S += days[i];
      i++;
    }
    console.log(S > days[i] ? i + 1 : i);
  }
}

function readline() {
  return process.stdin.readline();
}

survivalOnIsland();

This JavaScript code is a solution for the problem "Survival on an Island". It reads the input data and then solves the problem. The solution is based on the principle of greedy algorithms. In each day, the person can buy food from the maximum units. If the total units of food in the day is less than the daily purchase limit, the person buys all available food. If the total units of food is more than the daily purchase limit, the person buys the remaining food. The total units of food is kept track of in the variable `S`. The solution is printed in the end.

The time complexity of this solution is O(N) where N is the number of days. The space complexity is O(1) as no additional space is used.