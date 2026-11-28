import java.util.*;

public class Solution {
    public List<Integer> primesInRange(int low, int high) {
        List<Integer> res = new ArrayList<>();
        if (high < 2) return res;

        boolean[] isPrime = new boolean[high + 1];
        Arrays.fill(isPrime, true);
        isPrime[0] = isPrime[1] = false;

        for (int i = 2; (long) i * i <= high; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j <= high; j += i) {
                    isPrime[j] = false;
                }
            }
        }

        for (int i = Math.max(2, low); i <= high; i++) {
            if (isPrime[i]) res.add(i);
        }
        return res;
    }
}
