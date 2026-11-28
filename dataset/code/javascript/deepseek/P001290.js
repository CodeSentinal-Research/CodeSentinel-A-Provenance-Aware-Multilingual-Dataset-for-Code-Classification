function maxScore(A, B, C) {
  let min = Math.min(A, B, C);
  A -= min;
  B -= min;
  C -= min;

  let max = Math.max(A, B, C);
  A -= max;
  B -= max;
  C -= max;

  return min + max + (A + B + C);
}

console.log(maxScore(1, 1, 1));
In this code, we first find out the smallest number among A, B, and C. Then we subtract this number from all three piles (A, B, C). The remaining piles now contain the smallest number, so we can consider this as a candidate for the maximum score.

Then we find out the largest number among A, B, and C. This largest number represents the score we can obtain from removing the stones in the piles, not the stones. Therefore, we subtract this number from all three piles (A, B, C).

Finally, the score obtained is the sum of the smallest number, the largest number, and the remaining stones in all three piles.