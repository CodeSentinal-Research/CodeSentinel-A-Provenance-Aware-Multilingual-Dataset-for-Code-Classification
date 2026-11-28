function minDays(n, bloomDay, m, k) {
  if (n < m) return -1;
  
  bloomDay.sort((a, b) => a - b);
  let low = bloomDay[0], high = bloomDay[n - 1];
  let mid;
  
  while (low < high) {
    mid = Math.floor((low + high) / 2);
    
    if (check(bloomDay, n, m, k, mid)) {
      high = mid;
    } else {
      low = mid + 1;
    }
  }
  
  return high;
}

function check(bloomDay, n, m, k, currDay) {
  let bouquets = 0, flowers = 0;
  
  for (let i = 0; i < n; i++) {
    if (bloomDay[i] <= currDay) {
      flowers++;
      
      if (flowers === k) {
        flowers = 0;
        bouquets++;
        
        if (bouquets === m) {
          return true;
        }
      }
    } else {
      flowers = 0;
    }
  }
  
  return bouquets === m;
}