public class Solution {
    public String getSmallestString(int n, int k) {
        char[] res = new char[n];
        for (int i = 0; i < n; i++) res[i] = 'a';
        k -= n;

        for (int i = n - 1; i >= 0 && k > 0; i--) {
            int add = Math.min(25, k);
            res[i] = (char)('a' + add);
            k -= add;
        }
        return new String(res);
    }
}