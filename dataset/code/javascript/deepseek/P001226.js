function friendArrangement(N) {
  if (N === 1) return 1;

  return 2 * (18 * (N - 1) + 15) * (N - 1) / 12;
}

console.log(friendArrangement(3));