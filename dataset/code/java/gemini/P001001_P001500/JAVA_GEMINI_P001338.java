import java.util.*;

public class Solution {
    public List<Integer> sequentialDigits(int low, int high) {
        List<Integer> res = new ArrayList<>();
        int lowLen = String.valueOf(low).length();
        int highLen = String.valueOf(high).length();

        for (int len = lowLen; len <= highLen; len++) {
            for (int start = 1; start <= 10 - len; start++) {
                int num = 0;
                for (int d = start; d < start + len; d++) {
                    num = num * 10 + d;
                }
                if (num >= low && num <= high) {
                    res.add(num);
                }
            }
        }
        return res;
    }
}