import java.util.*;

public class Solution {
    public List<Integer> getFactors(int n) {
        List<Integer> factors = new ArrayList<>();
        if (n <= 0) return factors;
        for (int i = 1; (long) i * i <= n; i++) {
            if (n % i == 0) {
                factors.add(i);
                if (i * i != n) factors.add(n / i);
            }
        }
        Collections.sort(factors);
        return factors;
    }
}
